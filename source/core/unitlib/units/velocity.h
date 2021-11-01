// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/units/helper_macros.h"
#include "Sirelphy/source/core/unitlib/units/base/baseunit.h"
#include "Sirelphy/source/core/unitlib/units/base/dimension_fundamentals.h"

using namespace si;

namespace length { class QLength; }
namespace unittime { class QTime; }

namespace velocity {

	// Base unit
	UNIT_ADD_BASE(meter_per_second, meters_per_second, 1.0)
	UNIT_ADD_RELATIVE(light_speed, light_speeds, meter_per_second, 1.0 / c)

	UNIT_ADD_RELATIVE(km_per_hour, kms_per_hour, meter_per_second, 3.6)

	class QVelocity : public QUnit<double, dim_velocity> {
	public:
		constexpr QVelocity(const double& _val = 0) : QUnit(_val) {}

		// Base unit
		GENERATE_MEMBER_FUNCTIONS(meter_per_second, meters_per_second, m_per_s)


		// Normalize to c
		inline double relToC() const {
			return val / units_per_light_speed;
		}

		// Operators

		friend QUnit operator*(const QVelocity&, const QVelocity&);
		friend QVelocity operator/(const length::QLength&, const unittime::QTime&);
	};
}

template <class T>
constexpr velocity::QVelocity
operator/(const QUnit<T, dim_length>& lhs, const QUnit<T, dim_time>& rhs) {
	return velocity::QVelocity(lhs.getRaw() * rhs.getRaw());
}