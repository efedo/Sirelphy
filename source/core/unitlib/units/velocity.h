// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/unitlib/units/base.h"
#include "Sirelphy/source/core/unitlib/helpers/constants_private.h"

using namespace si;

namespace _units_private {
	UNIT_ADD_BASE(meter_per_second, meters_per_second, 1.0)
	UNIT_ADD_RELATIVE(light_speed, light_speeds, meter_per_second, 1.0 / _constants::c)
	UNIT_ADD_RELATIVE(km_per_hour, kms_per_hour, meter_per_second, 3.6)
}

namespace units {

	class Length;
	class Time;

	class Velocity : public Unit<double, _units_private::dim_velocity> {
	public:
		explicit constexpr Velocity(const double& _val = 0) : Unit(_val) {}
		constexpr Velocity(Unit<double, _units_private::dim_velocity> _oldunit) : Unit(_oldunit) {}

		// Base unit
		GENERATE_MEMBER_FUNCTIONS(meter_per_second, meters_per_second, m_per_s)
		GENERATE_MEMBER_FUNCTIONS(km_per_hour, kms_per_hour, km_per_h)

		// Normalize to c
		inline double relToC() const {
			return val / _units_private::units_per_light_speed;
		}
	};
}

