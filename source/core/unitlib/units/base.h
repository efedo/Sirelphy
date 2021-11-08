// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/helpers/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/helpers/helper_macros.h"
#include "Sirelphy/source/core/unitlib/helpers/dimension_fundamentals.h"
#include "Sirelphy/source/core/unitlib/helpers/dimension_templates.h"

// Advanced declaration
namespace _units_private {
	template <class T, class D>
	class _Unit;

	//template <class T, class D>
	//constexpr T get_raw(_Unit<T, D> const &);

	//template <class T, class D>
	//constexpr T set_raw(_Unit<T, D> const&, T);

	// Base unit
	template <class T, class D>
	class _Unit {
	public:
		constexpr _Unit(const T& _val = 0) : val(_val) {}
		constexpr _Unit(const _Unit& rhs) : val(rhs.val) {}

		void debugUnitPrint() {
			D::debugPrint();
		}
		inline void set_raw(const double& _val) { val = _val; }
		inline T get_raw() const { return val; }
	protected:
		//constexpr friend T (get_raw(_Unit<T, D> const &));
		//constexpr friend T (set_raw(_Unit<T, D> const&, T val));
		T val = 0.0;
	};

	//// Definition
	//template <class T, class D>
	//constexpr T get_raw(_Unit<T, D> const & unit) {
	//	return unit.get_raw();
	//}

	//template <class T, class D>
	//constexpr void set_raw(_Unit<T, D> const& unit, T val) {
	//	unit.set_raw(val);
	//}
};

namespace units {

	template <class T, class D>
	class Unit : public _units_private::_Unit<T, D> {
	public:
		constexpr Unit(const T& _val = 0) : _Unit(_val) {}
		constexpr Unit(const Unit& rhs) : _Unit(rhs.val) {}
	};

	using Mass = Unit<double, _units_private::dim_mass>;
	using Velocity = Unit<double, _units_private::dim_velocity>;
	using Energy = Unit<double, _units_private::dim_energy>;
	using Length = Unit<double, _units_private::dim_length>;
	using Distance = Length;
	using Position = Length;
	using Time = Unit<double, _units_private::dim_time>;
	using Duration = Time;

	// Operators
	template <class T, class D>
	constexpr Unit<T, D> operator+(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		return Unit<T, D>(lhs.get_raw() + rhs.get_raw());
	}

	template <class T, class D>
	constexpr Unit<T, D> operator-(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		return Unit<T, D>(lhs.get_raw() - rhs.get_raw());
	}

	template <class T, class D_LHS, class D_RHS>
	constexpr Unit<T, _units_private::unitDimensions_add<D_LHS, D_RHS >>
		operator*(const Unit<T, D_LHS>& lhs, const Unit<T, D_RHS>& rhs) {
		return Unit<T, _units_private::unitDimensions_add<D_LHS, D_RHS>>(lhs.get_raw() * rhs.get_raw());
	}

	template <class T, class D_LHS, class D_RHS>
	constexpr Unit<T, _units_private::unitDimensions_subtract<D_LHS, D_RHS>>
		operator/(const Unit<T, D_LHS>& lhs, const Unit<T, D_RHS>& rhs) {
		return Unit<T, _units_private::unitDimensions_subtract<D_LHS, D_RHS>>(lhs.get_raw() / rhs.get_raw());
	}

	template <class T, class D>
	constexpr Unit<T, D>& operator+=(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		lhs.set_raw(lhs.get_raw() + rhs.get_raw());
		return lhs;
	}

	template <class T, class D>
	constexpr Unit<T, D>& operator-=(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		lhs.set_raw(lhs.get_raw() - rhs.get_raw());
		return lhs;
	}

	template <class T, class D>
	constexpr Unit<T, D> operator*(Unit<T, D>& lhs, T rhs) {
		return Unit<T, D>(lhs.get_raw() * rhs);
	}

	template <class T, class D>
	constexpr Unit<T, D> operator*(T lhs, Unit<T, D>& rhs) {
		return rhs * lhs;
	}

	template <class T, class D>
	constexpr Unit<T, D> operator/(Unit<T, D>& lhs, T rhs) {
		return Unit<T, D>(lhs.get_raw() / rhs);
	}

	template <class T, class D>
	constexpr Unit<T, D> operator/(T lhs, Unit<T, D>& rhs) {
		return Unit<T, _units_private::unitDimensions_subtract<_units_private::dim_none, D>>(lhs / rhs.get_raw());
	}

	template <class T, class D>
	constexpr Unit<T, D> & operator*=(const Unit<T, D>& lhs, T& rhs) {
		lhs.set_raw(lhs.get_raw() * rhs);
		return lhs;
	}

	template <class T, class D>
	constexpr Unit<T, D> & operator/=(const Unit<T, D>& lhs, T rhs) {
		lhs.set_raw(lhs.get_raw() / rhs);
		return lhs;
	}
}