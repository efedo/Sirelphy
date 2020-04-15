// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/unitlib.h"
#include "Utilogeny/source/exceptions.h"

template <uint8_t ND> class cVector;
class cVector2D;
class cVector3D;
class cVector4D;

// Multidimensional Operations

//std::vector<double> getRandomDirection(unsigned int);

// Advanced declarations of vector friends

// https://isocpp.org/wiki/faq/templates#template-friends
template <uint8_t ND>
bool operator==(const cVector<ND>&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND> operator+(const cVector<ND>&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND> operator-(const cVector<ND>&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND> operator-(const cVector<ND>&);

template <uint8_t ND>
cVector<ND> operator*(const cVector<ND>&, const double&);

template <uint8_t ND>
cVector<ND> operator/(const cVector<ND>&, const double&);

template <uint8_t ND>
cVector<ND> operator*(const double&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND> operator/(const double&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND>& operator+=(cVector<ND>&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND>& operator-=(cVector<ND>&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND>& operator*=(cVector<ND>&, const double&);

template <uint8_t ND>
cVector<ND>& operator/=(cVector<ND>&, const double&);

template <uint8_t ND>
cVector<ND> direction(const cVector<ND>&, const cVector<ND>&);

template <uint8_t ND>
cVector<ND> direction(const cVector<ND>*, const cVector<ND>*);

template <uint8_t ND>
double angle(const cVector<ND>&, const cVector<ND>&); // Normal angle from first vector to second vector (0 to 1)

template <uint8_t ND>
double angle(const cVector<ND>*, const cVector<ND>*); // Normal angle from first vector to second vector (0 to 1)

template <uint8_t ND>
double distance(const cVector<ND>&, const cVector<ND>&); // Spatial distance from first vector to second vector

template <uint8_t ND>
double distance(const cVector<ND>*, const cVector<ND>*); // Spatial distance from first vector to second vector


// Instantiations of non-operator friends

//cVector<3> direction(const cVector<3>&, const cVector<3>&);
//cVector<3> direction(const cVector<3>*, const cVector<3>*);
//double angle(const cVector<3>&, const cVector<3>&); // Normal angle from first vector to seco3 vector (0 to 1)
//double angle(const cVector<3>*, const cVector<3>*); // Normal angle from first vector to seco3 vector (0 to 1)
//double distance(const cVector<3>&, const cVector<3>&); // Spatial distance from first vector to seco3 vector
//double distance(const cVector<3>*, const cVector<3>*); // Spatial distance from first vector to seco3 vector




// Multidimensional vector base class
// Eventually, cVectorND will only be used for dim > 4, with all operations for dim <= 4 handled by
// dedicated specialized objects (e.g. cVector3D will implement all functions directly).
// For now, however, I'm being lazy and using cVectorND as the backend for vectors of all dimensions

template <uint8_t ND>
class cVector {
public:
	cVector();
	//cVectorND(const uint8_t&);
	cVector(const cVector&);
	cVector& operator=(const cVector&);
	~cVector();

	cVector2D& get2D() const;
	cVector3D& get3D() const;
	cVector4D& get4D() const;

	// Vector information
	uint8_t						getDimensions() const { return _dimensions; }


	double& dim(const uint8_t&) const; // Gets direct access to dimension

	double magnitude() const; // Gets magnitude of vector
	void unitize();
	void scaleTo(const double&);
	void scaleBy(const double&);
	void zero(); // Flushes values to 0

	friend bool operator==<ND>(const cVector&, const cVector&);
	friend cVector operator+<ND>(const cVector&, const cVector&);
	friend cVector operator-<ND>(const cVector&, const cVector&);
	friend cVector operator-<ND>(const cVector&);
	friend cVector operator*<ND>(const cVector&, const double&);
	friend cVector operator/<ND>(const cVector&, const double&);
	friend cVector operator*<ND>(const double&, const cVector&);
	friend cVector operator/<ND>(const double&, const cVector&);
	friend cVector& operator+=<ND>(cVector&, const cVector&);
	friend cVector& operator-=<ND>(cVector&, const cVector&);
	friend cVector& operator*=<ND>(cVector&, const double&);
	friend cVector& operator/=<ND>(cVector&, const double&);

	double distance(const cVector& rhs) const {
		const uint8_t dimensions = getDimensions();
		if (dimensions != rhs.getDimensions()) throw_line("Trying to calculate distance between vectors with different numbers of dimensions");
		double sum = 0;
		for (uint8_t i = 0; i != dimensions; ++i) {
			const double dif = (double)(rhs._values[i] - _values[i]);
			sum += (dif * dif);
		}
		return sqrt(sum);
	}

	friend double distance(const cVector& lhs, const cVector& rhs) {
		return lhs.distance(rhs);
	}

	friend double distance(const cVector* lhs, const cVector* rhs) {
		if (!(lhs && rhs)) throw_line("Trying to get distance for vector with undefined pointer");
		return lhs->distance(*rhs);
	}

	cVector direction(const cVector& rhs) const {
		if (this == &rhs) throw_line("Cannot get direction of vector to itself");
		if (*this == rhs) throw_line("Cannot get direction of vectors at same position");
		cVector dirVec(rhs - *this);
		dirVec.unitize();
		return dirVec;
	}

	friend cVector direction(const cVector& lhs, const cVector& rhs) {
		return lhs.direction(rhs);
	}

	friend cVector direction(const cVector* lhs, const cVector* rhs) {
		if (!(lhs && rhs)) throw_line("Trying to get distance for vector with undefined pointer");
		return lhs->direction(*rhs);
	}

	// Normal angle from first vector to second vector (0 to 1)
	double angle(const cVector& rhs) const {
		return asin(distance(rhs));
		// not sure if this is in degrees, rads or what... check doc
	}

	// Normal angle from first vector to second vector (0 to 1)
	friend double angle(const cVector& lhs, const cVector& rhs) {
		return lhs.angle(rhs);
		// not sure if this is in degrees, rads or what... check doc
	}

	// Normal angle from first vector to second vector (0 to 1)
	friend double angle(const cVector* lhs, const cVector* rhs) {
		return lhs->angle(*rhs);
	}

	//cVector direction(const cVector&) const; // Unit direction from first vector to second vector
	//friend cVector<ND> direction(const cVector<ND>&, const cVector<ND>&); // Unit direction from first vector to second vector
	//friend cVector<ND> direction(const cVector<ND>*, const cVector<ND>*); // Unit direction from first vector to second vector
	//double angle(const cVector&) const; // Normal angle from first vector to second vector (0 to 1)
	//friend double angle(const cVector<ND>&, const cVector<ND>&); // Normal angle from first vector to second vector (0 to 1)
	//friend double angle(const cVector<ND>*, const cVector<ND>*); // Normal angle from first vector to second vector (0 to 1)
	//double distance(const cVector<ND>&) const; // Spatial distance from first vector to second vector
	//friend double distance(const cVector<ND>&, const cVector<ND>&); // Spatial distance from first vector to second vector
	//friend double distance(const cVector<ND>*, const cVector<ND>*); // Spatial distance from first vector to second vector
protected:
	double* _values = 0;
	// Number of dimensions
	uint8_t				_dimensions = ND;
};

