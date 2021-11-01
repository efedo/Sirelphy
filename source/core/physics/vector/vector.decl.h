// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"
#include "Utilogeny/source/core/exceptions.h"

template <uint8_t ND> class cVector;

using cVector2D = cVector<2>;
using cVector3D = cVector<3>;
using cVector4D = cVector<4>;

// Multidimensional Operations

//std::vector<double> getRandomDirection(unsigned int);

// Advanced declarations of vector friends

// https://isocpp.org/wiki/faq/templates#template-friends
template <uint8_t ND>
bool operator==(const cVector<ND>&, const cVector<ND>&);

template <uint8_t ND, uint8_t RD>
cVector<ND> operator+(const cVector<ND>&, const cVector<RD>&);

template <uint8_t ND, uint8_t RD>
cVector<ND> operator-(const cVector<ND>&, const cVector<RD>&);

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

template <uint8_t ND, uint8_t RD>
cVector<ND>& operator+=(cVector<ND>&, const cVector<RD>&);

template <uint8_t ND, uint8_t RD>
cVector<ND>& operator-=(cVector<ND>&, const cVector<RD>&);

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

namespace ctmath {
	template <class T>
	constexpr bool equal(T lhs, T rhs) { return lhs == rhs; }
}

template <uint8_t ND>
class cVector {
public:
	cVector();
	cVector(const cVector&);
	cVector& operator=(const cVector&);
	~cVector();

	// You have the following options:
	// 1. Use variadic arguments + static assert to enforce dimensionality
	// 2. Use SFINAI to always provide only the correct option for a vector of given dimensions

	template<uint8_t T_ = ND>
	cVector(const double nx, std::enable_if_t<std::ratio_equal<std::ratio<T_, 1>, std::ratio<1, 1>>::value>* = nullptr) 
		: _values(new double[ND])
	{
		x() = nx;
	};

	template<uint8_t T_ = ND>
	cVector(const double nx, const double ny, std::enable_if_t<std::ratio_equal<std::ratio<T_, 1>, std::ratio<2, 1>>::value>* = nullptr) 
		: _values(new double[ND])
	{
		x() = nx;
		y() = ny;
	};

	template<uint8_t T_ = ND>
	cVector(const double nx, const double ny, const double nz, std::enable_if_t<std::ratio_equal<std::ratio<T_, 1>, std::ratio<3, 1>>::value>* = nullptr) 
		: _values(new double[ND])
	{
		x() = nx;
		y() = ny;
		z() = nz;
	};

	template<uint8_t T_ = ND>
	cVector(const double nx, const double ny, const double nz, const double nt, std::enable_if_t<std::ratio_equal<std::ratio<T_, 1>, std::ratio<4, 1>>::value>* = nullptr) 
		: _values(new double[ND])
	{ 
		x() = nx; 
		y() = ny; 
		z() = nz; 
		t() = nt;
	};

	template<uint8_t T_ = ND>
	inline double& x(std::enable_if_t<std::ratio_greater_equal<std::ratio<T_, 1>, std::ratio<1, 1>>::value>* = nullptr) const { return dim(0); };

	template<uint8_t T_ = ND>
	inline double& y(std::enable_if_t<std::ratio_greater_equal<std::ratio<T_, 1>, std::ratio<2, 1>>::value>* = nullptr) const { return dim(1); };

	template<uint8_t T_ = ND>
	inline double& z(std::enable_if_t<std::ratio_greater_equal<std::ratio<T_, 1>, std::ratio<3, 1>>::value>* = nullptr) const { return dim(2); };

	template<uint8_t T_ = ND>
	inline double& t(std::enable_if_t<std::ratio_greater_equal<std::ratio<T_, 1>, std::ratio<4, 1>>::value>* = nullptr) const { return dim(3); };

	// Vector information
	uint8_t						getDimensions() const { return ND; }

	inline double& dim(const uint8_t&) const; // Gets direct access to dimension

	double magnitude() const; // Gets magnitude of vector
	void randomUnit(); // Generates a random unit vector
	bool isNotZero(); // Checks if not zero
	void unitize();
	void scaleTo(const double&);
	void scaleBy(const double&);
	void zero(); // Flushes values to 0
	friend bool operator==<ND>(const cVector&, const cVector&);
	template <uint8_t RD> friend cVector<ND> operator+(const cVector<ND>&, const cVector<RD>&);
	template <uint8_t RD> friend cVector<ND> operator-(const cVector<ND>&, const cVector<RD>&);
	//template <uint8_t RD> friend cVector operator+<ND, RD>(const cVector<ND>&, const cVector<RD>&);
	//template <uint8_t RD> friend cVector operator-<ND, RD>(const cVector<ND>&, const cVector<RD>&);
	friend cVector operator-<ND>(const cVector&);
	friend cVector operator*<ND>(const cVector&, const double&);
	friend cVector operator/<ND>(const cVector&, const double&);
	friend cVector operator*<ND>(const double&, const cVector&);
	friend cVector operator/<ND>(const double&, const cVector&);
	//template <uint8_t RD> friend cVector<ND>& operator+=(cVector<ND>&, const cVector<RD>&);
	//template <uint8_t RD> friend cVector<ND>& operator-=(cVector<ND>&, const cVector<RD>&);
	//template <uint8_t RD> friend cVector& operator+=<ND, RD>(cVector<ND>&, const cVector<RD>&);
	//template <uint8_t RD> friend cVector& operator-=<ND, RD>(cVector<ND>&, const cVector<RD>&);
	friend cVector& operator*=<ND>(cVector&, const double&);
	friend cVector& operator/=<ND>(cVector&, const double&);

	double distance(const cVector& rhs) const {
		const uint8_t dimensions = getDimensions();
		if (dimensions != rhs.getDimensions()) throwl("Trying to calculate distance between vectors with different numbers of dimensions");
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
		if (!(lhs && rhs)) throwl("Trying to get distance for vector with undefined pointer");
		return lhs->distance(*rhs);
	}

	cVector direction(const cVector& rhs) const {
		if (this == &rhs) throwl("Cannot get direction of vector to itself");
		if (*this == rhs) throwl("Cannot get direction of vectors at same position");
		cVector dirVec(rhs - *this);
		dirVec.unitize();
		return dirVec;
	}

	friend cVector direction(const cVector& lhs, const cVector& rhs) {
		return lhs.direction(rhs);
	}

	friend cVector direction(const cVector* lhs, const cVector* rhs) {
		if (!(lhs && rhs)) throwl("Trying to get distance for vector with undefined pointer");
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


	//template<uint8_t T_ = ND>
	//cVector<4>(const double nx, const double ny, const double nz, const double nt) { x() = nx; y() = ny; z() = nz; t() = nt; }

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
};
