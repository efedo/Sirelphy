// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/helpers/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/helpers/helper_macros.h"
#include "Sirelphy/source/core/unitlib/helpers/dimension_fundamentals.h"
#include "Sirelphy/source/core/unitlib/helpers/dimension_templates.h"

namespace units {

	// Base unit
	template <class T, class D>
	class Unit {
	public:

		constexpr Unit(const T& _val = 0) : val(_val) {}
		constexpr Unit(const Unit& rhs) : val(rhs.val) {}

		const Unit& getBaseUnit() const {
			return *(static_cast<const Unit*>(this));
		}

		void debugUnitPrint() {
			D::debugPrint();
		}

		inline void setRaw(const double& _val) { val = _val; }
		inline T getRaw() const { return val; }
		//	inline cRunTimeDimensions getDimensions() const { return D::getDimensionsRunTime(); }

		//	template <class T, class D>
		constexpr friend T getRaw(Unit<T, D> orig) {
			return orig.val;
		}
	protected:
		T val;
	};

	// Operators
	template <class T, class D>
	constexpr Unit<T, D> operator+(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		return Unit<T, D>(lhs.getRaw() + rhs.getRaw());
	}

	template <class T, class D>
	constexpr Unit<T, D> operator-(const Unit<T, D>& lhs, const Unit<T, D>& rhs) {
		return Unit<T, D>(lhs.getRaw() - rhs.getRaw());
	}

	template <class T, class D_LHS, class D_RHS>
	constexpr Unit<T, _units_private::unitDimensions_add<D_LHS, D_RHS >>
		operator*(const Unit<T, D_LHS>& lhs, const Unit<T, D_RHS>& rhs) {
		return Unit<T, _units_private::unitDimensions_add<D_LHS, D_RHS>>(lhs.getRaw() * rhs.getRaw());
	}

	template <class T, class D_LHS, class D_RHS>
	constexpr Unit<T, _units_private::unitDimensions_subtract<D_LHS, D_RHS>>
		operator/(const Unit<T, D_LHS>& lhs, const Unit<T, D_RHS>& rhs) {
		return Unit<T, _units_private::unitDimensions_subtract<D_LHS, D_RHS>>(lhs.getRaw() / rhs.getRaw());
	}

}