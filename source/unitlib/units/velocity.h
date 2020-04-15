// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/si_prefixes.h"
#include "Sirelphy/source/unitlib/units/helper_macros.h"
#include "Sirelphy/source/unitlib/units/base/baseunit.h"
#include "Sirelphy/source/unitlib/units/base/dimension_fundamentals.h"

using namespace si;

namespace length { class QLength; }
namespace unittime { class QTime; }

namespace velocity {

	// Base unit
	UNIT_ADD_BASE(light_speed, light_speed, 1.0)
	UNIT_ADD_RELATIVE(meter_per_second, meters_per_second, light_speed, 1.0 / c)

	class QVelocity : public QUnit<double, dim_velocity> {
	public:
		constexpr QVelocity(const double& _val = 0) : QUnit(_val) {}

		// Normalize to c
		inline double relToC() const {
			return val / units_per_light_speed;
		}

		// Operators

		friend QUnit operator*(const QVelocity&, const QVelocity&);
		friend QVelocity operator/(const length::QLength&, const unittime::QTime&);
	};
}