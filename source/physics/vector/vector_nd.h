// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_nd.decl.h"
#include "Sirelphy/source/utils/randomnumbers.h"
#include "Utilogeny/source/exceptions.h"
#include "Utilogeny/source/randomnumbers.h"

template <uint8_t ND>
cVector<ND>::cVector()
//: _dimensions(ND)
{
	_values = new double[ND+5];
	memset(_values, double(0), sizeof(double) * ND);
	//for (uint8_t i = 0; i != ND; ++i) {
	//	_values[i] = 0.0;
	//}
}

template <uint8_t ND>
cVector<ND>::cVector(const cVector<ND>& rhs)
{
	constexpr uint8_t dimensions = ND;
	_values = new double[dimensions];
	for (uint8_t i = 0; i != dimensions; ++i) {
		_values[i] = rhs._values[i];
	}
}

////template <uint8_t ND>
//cVector2D& cVector<2>::get2D() const {
//	return *const_cast<cVector2D*>(static_cast<const cVector2D*>(this));
//}

//template <uint8_t ND>
//cVector2D& cVector<ND>::get2D() const {
//	throw_line("Base vector has incorrect number of dimensions");
//}

////template <uint8_t ND>
//cVector3D& cVector<3>::get3D() const {
//	return *const_cast<cVector3D*>(static_cast<const cVector3D*>(this));
//}

//template <uint8_t ND>
//cVector3D& cVector<ND>::get3D() const {
//	throw_line("Base vector has incorrect number of dimensions");
//}

//cVector4D& cVector<4>::get4D() const {
//	return *const_cast<cVector4D*>(static_cast<const cVector4D*>(this));
//}

//template <uint8_t ND>
//cVector4D& cVector<ND>::get4D() const {
//	throw_line("Base vector has incorrect number of dimensions");
//}

template <uint8_t ND>
cVector<ND>& cVector<ND>::operator=(const cVector<ND>& rhs)
{
	if (this == &rhs) return *this;
	constexpr uint8_t dimensions = ND;
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
inline double & cVector<ND>::dim(const uint8_t & dimnum) const {
	#ifdef DEBUG
	if (dimnum >= ND) throw_line("Trying to access non-existant vector dimension");
	#endif //DEBUG
	return _values[dimnum];
}

template <uint8_t ND>
double cVector<ND>::magnitude() const {
	constexpr uint8_t dimensions = ND;
	double sum = 0;
	for (uint8_t i = 0; i != dimensions; ++i) {
		sum += (double)_values[i] * (double)_values[i];
	}
	sum = sqrt(sum);
	return sum;
}

// Generates a random unit vector
template <uint8_t ND>
void cVector<ND>::randomUnit() {
	constexpr uint8_t dimensions = ND;
	bool incomplete = true;
	while (incomplete) {
		for (uint8_t i = 0; i != dimensions; ++i) {
			_values[i] = globals::mersenneTwister.randomDouble(0, 1);
		}
		if (this->isNotZero()) incomplete = false;
	}
	this->unitize();
}

// Checks if not zero
template <uint8_t ND>
bool cVector<ND>::isNotZero() {
	constexpr uint8_t dimensions = ND;
	for (uint8_t i = 0; i != dimensions; ++i) {
		if (_values[i]) return true;
	}
	return false;
}

template <uint8_t ND>
void cVector<ND>::unitize() {
	scaleTo(1.0);
}

// Flushes values to 0
template <uint8_t ND>
void cVector<ND>::zero() {
	constexpr uint8_t dimensions = ND;
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
	constexpr uint8_t dimensions = ND;
	for (uint8_t i = 0; i != dimensions; ++i) {
		_values[i] = (double)(scaleFactor * (double)_values[i]);
	}
}

template <uint8_t ND>
bool operator==(const cVector<ND>& lhs, const cVector<ND>& rhs) {
	constexpr uint8_t dimensions = ND;
	//if (dimensions != rhs.getDimensions()) throw_line("Trying to compare vectors with different numbers of dimensions");
	for (uint8_t i = 0; i != dimensions; ++i) {
		if (lhs._values[i] != rhs._values[i]) return false;
	}
	return true;
}

// Uint8_t template comparitor
template<uint8_t A, uint8_t B>
constexpr uint8_t greaterTemplateUint8()
{
	if (A > B) return A;
	else return B;
}

template <uint8_t ND, uint8_t RD>
cVector<ND> operator+(const cVector<ND>& lhs, const cVector<RD>& rhs) {
	static_assert(RD <= ND, "Right vector must be same or viewer dimensions than left");
	cVector<ND> newVec;
	uint8_t i = 0;
	for (; i != RD; ++i) {
		newVec.dim(i)= lhs.dim(i) + rhs.dim(i);
	}
	for (; i != ND; ++i) {
		newVec.dim(i) = lhs.dim(i);
	}
	return newVec;
}

template <uint8_t ND, uint8_t RD>
cVector<ND> operator-(const cVector<ND>& lhs, const cVector<RD>& rhs) {
	static_assert(RD <= ND, "Right vector must be same or viewer dimensions than left");
	cVector<ND> newVec;
	uint8_t i = 0;
	for (; i != RD; ++i) {
		newVec.dim(i) = lhs.dim(i) - rhs.dim(i);
	}
	for (; i != ND; ++i) {
		newVec.dim(i) = lhs.dim(i);
	}
	return newVec;
}

template <uint8_t ND>
cVector<ND> operator-(const cVector<ND>& rhs) {
	constexpr uint8_t dimensions = ND;
	cVector<ND> unaryNeg;
	for (uint8_t i = 0; i != dimensions; ++i) {
		unaryNeg._values[i] = -rhs._values[i];
	}
	return unaryNeg;
}

template <uint8_t ND>
cVector<ND> operator*(const cVector<ND>& vec, const double & mult) {
	constexpr uint8_t dimensions = ND;
	cVector<ND> newVec;
	/// Scale a vector by a given factor
	for (uint8_t i = 0; i != dimensions; ++i) {
		newVec._values[i] = (double)((double)(vec._values[i]) * mult);
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

template <uint8_t ND, uint8_t RD>
cVector<ND>& operator+=(cVector<ND>& lhs, const cVector<RD>& rhs) {
	static_assert(RD <= ND, "Right vector must be same or viewer dimensions than left");
	for (uint8_t i = 0; i != RD; ++i) {
		lhs.dim(i) += rhs.dim(i);
	}
	return lhs;
}

template <uint8_t ND, uint8_t RD>
cVector<ND>& operator-=(cVector<ND>& lhs, const cVector<RD>& rhs) {
	static_assert(RD <= ND, "Right vector must be same or viewer dimensions than left");
	for (uint8_t i = 0; i != RD; ++i) {
		lhs.dim(i) -= rhs.dim(i);
	}
	return lhs;
}

template <uint8_t ND>
cVector<ND>& operator*=(cVector<ND>& lhs, const double & rhs) {
	constexpr uint8_t dimensions = ND;
	for (uint8_t i = 0; i != dimensions; ++i) {
		lhs._values[i] = (double)((double)(lhs._values[i]) * rhs);
	}
	return lhs;
}

template <uint8_t ND>
cVector<ND>& operator/=(cVector<ND>& lhs, const double & rhs) {
	return operator*=(lhs, 1.0 / rhs); // speedier
}

