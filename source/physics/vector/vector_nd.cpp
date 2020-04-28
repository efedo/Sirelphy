// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/vector_2d.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"
#include "Sirelphy/source/physics/vector/vector_4d.h"
#include "Sirelphy/source/utils/randomnumbers.h"
#include "Utilogeny/source/exceptions.h"


// Explicit instantiations

template class cVector<3>;
template bool operator==(const cVector<3>&, const cVector<3>&);
template cVector<3> operator+(const cVector<3>&, const cVector<3>&);
template cVector<3> operator-(const cVector<3>&, const cVector<3>&);
template cVector<3> operator-(const cVector<3>&);
template cVector<3> operator*(const cVector<3>&, const double&);
template cVector<3> operator/(const cVector<3>&, const double&);
template cVector<3> operator*(const double&, const cVector<3>&);
template cVector<3> operator/(const double&, const cVector<3>&);
template cVector<3>& operator+=(cVector<3>&, const cVector<3>&);
template cVector<3>& operator-=(cVector<3>&, const cVector<3>&);
template cVector<3>& operator*=(cVector<3>&, const double&);
template cVector<3>& operator/=(cVector<3>&, const double&);

template <uint8_t ND>
cVector<ND>::cVector()
//: _dimensions(ND)
{
	_values = new double[ND];
}

template <uint8_t ND>
cVector<ND>::cVector(const cVector<ND>& rhs)
{
	const uint8_t dimensions = ND;
	_values = new double[dimensions];
	for (uint8_t i = 0; i != dimensions; ++i) {
		_values[i] = rhs._values[i];
	}
}

//template <uint8_t ND>
cVector2D& cVector<2>::get2D() const {
	return *const_cast<cVector2D*>(static_cast<const cVector2D*>(this));
}

template <uint8_t ND>
cVector2D& cVector<ND>::get2D() const {
	throw_line("Base vector has incorrect number of dimensions");
}

//template <uint8_t ND>
cVector3D& cVector<3>::get3D() const {
	return *const_cast<cVector3D*>(static_cast<const cVector3D*>(this));
}

template <uint8_t ND>
cVector3D& cVector<ND>::get3D() const {
	throw_line("Base vector has incorrect number of dimensions");
}

cVector4D& cVector<4>::get4D() const {
	return *const_cast<cVector4D*>(static_cast<const cVector4D*>(this));
}

template <uint8_t ND>
cVector4D& cVector<ND>::get4D() const {
	throw_line("Base vector has incorrect number of dimensions");
}

template <uint8_t ND>
cVector<ND>& cVector<ND>::operator=(const cVector<ND>& rhs)
{
	if (this == &rhs) return *this;
	const uint8_t dimensions = ND;
	//if (_dimensions != rhs._dimensions) throw_line("Mismatched vector dimensions")
	for (uint8_t i = 0; i != dimensions; ++i) {
		_values[i] = rhs._values[i];
	}
	return *this;
}

template <uint8_t ND>
cVector<ND>::~cVector()
{
	if (_values) delete[] _values;
}

template <uint8_t ND>
double & cVector<ND>::dim(const uint8_t & dimnum) const {
	const uint8_t dimensions = ND;
	if (dimnum >= dimensions) throw_line("Trying to access non-existant vector dimension");
	return _values[dimnum];
}

template <uint8_t ND>
double cVector<ND>::magnitude() const {
	const uint8_t dimensions = ND;
	double sum = 0;
	for (uint8_t i = 0; i != dimensions; ++i) {
		sum += (double)_values[i] * (double)_values[i];
	}
	sum = sqrt(sum);
	return sum;
}

template <uint8_t ND>
void cVector<ND>::unitize() {
	scaleTo(1.0);
}

// Flushes values to 0
template <uint8_t ND>
void cVector<ND>::zero() {
	const uint8_t dimensions = ND;
	for (uint8_t i = 0; i != dimensions; ++i) {
		_values[i] = 0;
	}
}

/// Scales a vector to magnitude
template <uint8_t ND>
void cVector<ND>::scaleTo(const double & targetMagnitude) {
	if (!isfinite(targetMagnitude)) throw_line("Cannot scale vector to non-finite magnitude");
	const double mag = magnitude();
	if (!isfinite(mag)) throw_line("Cannot scale vector with non-finite magnitude to a target magnitude");
	const double scaleFactor = targetMagnitude / mag;
	scaleBy(scaleFactor);
}

template <uint8_t ND>
void cVector<ND>::scaleBy(const double & scaleFactor) {
	const uint8_t dimensions = ND;
	for (uint8_t i = 0; i != dimensions; ++i) {
		_values[i] = (double)(scaleFactor * (double)_values[i]);
	}
}

template <uint8_t ND>
bool operator==(const cVector<ND>& lhs, const cVector<ND>& rhs) {
	const uint8_t dimensions = ND;
	//if (dimensions != rhs.getDimensions()) throw_line("Trying to compare vectors with different numbers of dimensions");
	for (uint8_t i = 0; i != dimensions; ++i) {
		if (lhs._values[i] != rhs._values[i]) return false;
	}
	return true;
}

template <uint8_t ND>
cVector<ND> operator+(const cVector<ND>& lhs, const cVector<ND>& rhs) {
	const uint8_t dimensions = ND;
	//if (dimensions != rhs.getDimensions()) throw_line("Trying to add vectors with different numbers of dimensions");

	cVector<ND> newVec;

	for (uint8_t i = 0; i != dimensions; ++i) {
		newVec._values[i] = lhs._values[i] + rhs._values[i];
	}
	return newVec;
}

template <uint8_t ND>
cVector<ND> operator-(const cVector<ND>& lhs, const cVector<ND>& rhs) {
	const uint8_t dimensions = ND;
	//if (dimensions != rhs.getDimensions()) throw_line("Trying to subtract vectors with different numbers of dimensions");

	cVector<ND> newVec;

	for (uint8_t i = 0; i != dimensions; ++i) {
		newVec._values[i] = lhs._values[i] - rhs._values[i];
	}
	return newVec;
}

template <uint8_t ND>
cVector<ND> operator-(const cVector<ND>& rhs) {
	const uint8_t dimensions = ND;
	cVector<ND> unaryNeg;

	for (uint8_t i = 0; i != dimensions; ++i) {
		rhs._values[i] = -rhs._values[i];
	}
	return unaryNeg;
}

template <uint8_t ND>
cVector<ND> operator*(const cVector<ND>& vec, const double & mult) {
	const uint8_t dimensions = ND;
	cVector<ND> newVec;
	/// Scale a vector by a given factor
	for (uint8_t i = 0; i != dimensions; ++i) {
		vec._values[i] = (double)((double)(vec._values[i]) * mult);
	}
	return newVec;
}

template <uint8_t ND>
cVector<ND> operator/(const cVector<ND>& vec, const double & div) {
	const double mult = 1 / div;
	return vec * mult;
}

template <uint8_t ND>
cVector<ND> operator*(const double & mult, const cVector<ND>& vec) {
	return operator*(vec, mult);
}

template <uint8_t ND>
cVector<ND> operator/(const double & /*div*/, const cVector<ND>& /*vec*/) {
	throw_line_not_implemented;
}

template <uint8_t ND>
cVector<ND>& operator+=(cVector<ND>& lhs, const cVector<ND>& rhs) {
	const uint8_t dimensions = ND;
	//if (dimensions != rhs.getDimensions()) throw_line("Trying to add vectors with different numbers of dimensions");
	for (uint8_t i = 0; i != dimensions; ++i) {
		lhs._values[i] += rhs._values[i];
	}
	return lhs;
}

template <uint8_t ND>
cVector<ND>& operator-=(cVector<ND>& lhs, const cVector<ND>& rhs) {
	const uint8_t dimensions = ND;
	//if (dimensions != rhs.getDimensions()) throw_line("Trying to subtract vectors with different numbers of dimensions");
	for (uint8_t i = 0; i != dimensions; ++i) {
		lhs._values[i] -= rhs._values[i];
	}
	return lhs;
}

template <uint8_t ND>
cVector<ND>& operator*=(cVector<ND>& lhs, const double & rhs) {
	const uint8_t dimensions = ND;
	for (uint8_t i = 0; i != dimensions; ++i) {
		lhs._values[i] = (double)((double)(lhs._values[i]) * rhs);
	}
	return lhs;
}

template <uint8_t ND>
cVector<ND>& operator/=(cVector<ND>& lhs, const double & rhs) {
	return operator*=(lhs, 1.0 / rhs); // speedier
}

