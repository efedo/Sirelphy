// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/si_prefixes.h"
#include "Sirelphy/source/unitlib/units/helper_macros.h"
#include "Sirelphy/source/unitlib/units/base/baseunit.h"
#include "Sirelphy/source/unitlib/units/base/dimension_fundamentals.h"
#include "Sirelphy/source/unitlib/constants.h"

using namespace si;

namespace unittime { class QTime; };
namespace velocity { class QVelocity; };


namespace length {

	// Base unit
	UNIT_ADD_BASE(light_second, light_seconds, 1.0)
	UNIT_ADD_RELATIVE(meter, meters, light_second, 1.0 / c)

	// SI derived units
	UNIT_ADD_SIPREFIXES(meter, meters)

	// Non-SI units
	UNIT_ADD_RELATIVE(foot, feet, meter, 381 / 1250)
	UNIT_ADD_RELATIVE(yard, yards, foot, 3)
	UNIT_ADD_RELATIVE(inch, inches, foot, 1 / 12)
	UNIT_ADD_RELATIVE(mile, miles, foot, 5280)
	UNIT_ADD_RELATIVE(nautical_mile, nautical_miles, meter, 1852)
	UNIT_ADD_RELATIVE(astronomical_unit, astronomical_units, meter, 149597870700)
	UNIT_ADD_RELATIVE(light_year, light_years, meter, 9460730472580800)
	UNIT_ADD_RELATIVE(parsec, parsecs, light_year, 3.26156)
	UNIT_ADD_RELATIVE(angstrom, angstroms, nanometer, 0.1)

	class QLength : public QUnit<double, dim_length> {
	public:
		constexpr QLength(const double & _val = 0) : QUnit(_val) {}

		// Base unit
		GENERATE_MEMBER_FUNCTIONS(meter, meters, m)

		// SI prefix units
		GENERATE_MEMBER_FUNCTIONS_SIPREFIXES(meter, meters, m)

		// Non-SI units
		GENERATE_MEMBER_FUNCTIONS(foot, feet, ft)
		GENERATE_MEMBER_FUNCTIONS(yard, yards, yd)
		GENERATE_MEMBER_FUNCTIONS(inch, inches, in)
		GENERATE_MEMBER_FUNCTIONS(mile, miles, mi)
		GENERATE_MEMBER_FUNCTIONS(nautical_mile, nautical_miles, nmi)
		GENERATE_MEMBER_FUNCTIONS(astronomical_unit, astronomical_units, au)
		GENERATE_MEMBER_FUNCTIONS(light_year, light_years, ly)
		GENERATE_MEMBER_FUNCTIONS(parsec, parsecs, pc)
		GENERATE_MEMBER_FUNCTIONS(angstrom, angstroms, ang)

		// Math functions
		friend QLength operator*(const velocity::QVelocity&, const unittime::QTime&);
	};
	typedef QLength QDistance;
	typedef QLength QPosition;

	// Literals

	// Base unit
	GENERATE_LITERALS(QLength, meter, meters, m)

	// SI prefix units
	GENERATE_LITERALS_SIPREFIXES(QLength, meter, meters, m)

	// Non-SI units
	GENERATE_LITERALS(QLength, foot, feet, ft)
	GENERATE_LITERALS(QLength, yard, yards, yd)
	GENERATE_LITERALS(QLength, inch, inches, in)
	GENERATE_LITERALS(QLength, mile, miles, mi)
	GENERATE_LITERALS(QLength, nautical_mile, nautical_miles, nmi)
	GENERATE_LITERALS(QLength, astronomical_unit, astronomical_units, au)
	GENERATE_LITERALS(QLength, light_year, light_years, ly)
	GENERATE_LITERALS(QLength, parsec, parsecs, pc)
	GENERATE_LITERALS(QLength, angstrom, angstroms, ang)
}