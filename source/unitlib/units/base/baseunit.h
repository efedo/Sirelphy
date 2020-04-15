// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/units/base/dimension_templates.h"

// Base unit
template <class T, class D>
class QUnit {
public:

	constexpr QUnit(const T& _val = 0) : val(_val) {}
	constexpr QUnit(const QUnit& rhs) : val(rhs.val) {}

	const QUnit& getBaseUnit() const {
		return *(static_cast<const QUnit *>(this));
	}

	inline void setRaw(const double & _val) { val = _val; }
	inline T getRaw() const { return val; }
//	inline cRunTimeDimensions getDimensions() const { return D::getDimensionsRunTime(); }

//	template <class T, class D>
	constexpr friend T getRaw(QUnit<T, D> orig) {
		return orig.val;
	}
protected:
	T val;
};

// Operators
template <class T, class D>
constexpr QUnit<T, D> operator+(const QUnit<T, D>& lhs, const QUnit<T, D>& rhs) {
	return QUnit<T, D>(lhs.getRaw() + rhs.getRaw());
}

template <class T, class D>
constexpr QUnit<T, D> operator-(const QUnit<T, D>& lhs, const QUnit<T, D>& rhs) {
	return QUnit<T, D>(lhs.getRaw() - rhs.getRaw());
}

template <class T, class D_LHS, class D_RHS>
constexpr QUnit<T, unitDimensions_add<D_LHS, D_RHS >>
	operator*(const QUnit<T, D_LHS>& lhs, const QUnit<T, D_RHS>& rhs) {
	return QUnit<T, unitDimensions_add<D_LHS, D_RHS>>(lhs.getRaw() * rhs.getRaw());
}

template <class T, class D_LHS, class D_RHS>
constexpr QUnit<T, unitDimensions_subtract<D_LHS, D_RHS>>
operator/(const QUnit<T, D_LHS>& lhs, const QUnit<T, D_RHS>& rhs) {
	return QUnit<T, unitDimensions_subtract<D_LHS, D_RHS>>(lhs.getRaw() * rhs.getRaw());
}