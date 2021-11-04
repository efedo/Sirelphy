// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/units/base/baseunit.h"
#include "Sirelphy/source/core/unitlib/units/base/dimension_fundamentals.h"

using namespace si;

namespace units {

	// Base unit
	UNIT_ADD_BASE(second, seconds, 1.0)

	// SI derived units
	UNIT_ADD_SIPREFIXES(second, seconds)

	// Non-SI units
	UNIT_ADD_RELATIVE(minute, minutes, second, 60) // min
	UNIT_ADD_RELATIVE(hour, hours, minute, 60) // hr
	UNIT_ADD_RELATIVE(day, days, hour, 24) // d
	UNIT_ADD_RELATIVE(week, weeks, day, 7) // wk
	UNIT_ADD_RELATIVE(year, years, day, 365) // yr
	UNIT_ADD_RELATIVE(julian_year, julian_years, second, 31557600) // yr_j
	UNIT_ADD_RELATIVE(gregorian_year, gregorian_years, second, 31556952) // yr_g

	class QTime : public QUnit<double, _units_private::dim_time> {
	public:

		explicit constexpr QTime(const double& _val = 0) : QUnit(_val) {}

		// Base unit
		GENERATE_MEMBER_FUNCTIONS(second, seconds, s)

		// SI prefix units
		GENERATE_MEMBER_FUNCTIONS_SIPREFIXES(second, seconds, s)

		// Non-SI units
		GENERATE_MEMBER_FUNCTIONS(minute, minutes, min)
		GENERATE_MEMBER_FUNCTIONS(hour, hours, hr)
		GENERATE_MEMBER_FUNCTIONS(day, days, d)
		GENERATE_MEMBER_FUNCTIONS(week, weeks, wk)
		GENERATE_MEMBER_FUNCTIONS(year, years, yr)
		GENERATE_MEMBER_FUNCTIONS(julian_year, julian_years, yr_j)
		GENERATE_MEMBER_FUNCTIONS(gregorian_year, gregorian_years, yr_g)

		// Math functions
		//friend QLength operator*(const velocity::QVelocity&, const time::QTime&);
	};
	typedef QTime QDuration;

	// Literals

	// Base unit
	GENERATE_LITERALS(QTime, second, seconds, s)

	// SI prefix units
	GENERATE_LITERALS_SIPREFIXES(QTime, second, seconds, s)

	// Non-SI units
	GENERATE_LITERALS(QTime, minute, minutes, min)
	GENERATE_LITERALS(QTime, hour, hours, hr)
	GENERATE_LITERALS(QTime, day, days, d)
	GENERATE_LITERALS(QTime, week, weeks, wk)
	GENERATE_LITERALS(QTime, year, years, yr)
	GENERATE_LITERALS(QTime, julian_year, julian_years, yr_j)
	GENERATE_LITERALS(QTime, gregorian_year, gregorian_years, yr_g)
}