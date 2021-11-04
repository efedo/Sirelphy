// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/helpers/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/helpers/helper_macros.h"
#include "Sirelphy/source/core/unitlib/helpers/dimension_fundamentals.h"
#include "Sirelphy/source/core/unitlib/helpers/dimension_templates.h"

// Advanced declaration
namespace units {
	template <class T, class D>
	class Unit;
}

// Advanced declaration
namespace _units_private {
	template <class T, class D>
	constexpr T get_raw(::units::Unit<T, D> const &);
};

namespace units {

	// Base unit
	template <class T, class D>
	class Unit {
	public:

		constexpr Unit(const T& _val = 0) : val(_val) {}
		constexpr Unit(const Unit& rhs) : val(rhs.val) {}

		void debugUnitPrint() {
			D::debugPrint();
		}
	protected:
		constexpr friend T (::_units_private::get_raw(Unit<T, D> const &));
		T val;
		const Unit& getBaseUnit() const {
			return *(static_cast<const Unit*>(this));
		}
		inline void set_raw(const double& _val) { val = _val; }
		inline T get_raw() const { return val; }
	};
}

namespace _units_private {
	// Definition
	template <class T, class D>
	constexpr T get_raw(::units::Unit<T, D> const & unit) {
		return unit.get_raw();
	}
};

namespace units {

	// Operators
	template <class T, class D>
	constexpr Unit<T, D> operator+(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		return Unit<T, D>(_units_private::get_raw(lhs) + _units_private::get_raw(rhs));
	}

	template <class T, class D>
	constexpr Unit<T, D> operator-(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		return Unit<T, D>(_units_private::get_raw(lhs) - _units_private::get_raw(rhs));
	}

	template <class T, class D_LHS, class D_RHS>
	constexpr Unit<T, _units_private::unitDimensions_add<D_LHS, D_RHS >>
		operator*(const Unit<T, D_LHS>& lhs, const Unit<T, D_RHS>& rhs) {
		return Unit<T, _units_private::unitDimensions_add<D_LHS, D_RHS>>(_units_private::get_raw(lhs) * _units_private::get_raw(rhs));
	}

	template <class T, class D_LHS, class D_RHS>
	constexpr Unit<T, _units_private::unitDimensions_subtract<D_LHS, D_RHS>>
		operator/(const Unit<T, D_LHS>& lhs, const Unit<T, D_RHS>& rhs) {
		return Unit<T, _units_private::unitDimensions_subtract<D_LHS, D_RHS>>(_units_private::get_raw(lhs) / _units_private::get_raw(rhs));
	}

}