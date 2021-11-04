// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/unitlib/units/base.h"
#include "Sirelphy/source/core/unitlib/helpers/constants_private.h"

using namespace si;

namespace _units_private {
	UNIT_ADD_BASE(meter, meters, 1.0)
	UNIT_ADD_RELATIVE(light_second, light_seconds, meter, _constants::c)
	UNIT_ADD_SIPREFIXES(meter, meters)
	UNIT_ADD_RELATIVE(foot, feet, meter, 381 / 1250)
	UNIT_ADD_RELATIVE(yard, yards, foot, 3)
	UNIT_ADD_RELATIVE(inch, inches, foot, 1 / 12)
	UNIT_ADD_RELATIVE(mile, miles, foot, 5280)
	UNIT_ADD_RELATIVE(nautical_mile, nautical_miles, meter, 1852)
	UNIT_ADD_RELATIVE(astronomical_unit, astronomical_units, meter, 149597870700)
	UNIT_ADD_RELATIVE(light_year, light_years, meter, 9460730472580800)
	UNIT_ADD_RELATIVE(parsec, parsecs, light_year, 3.26156)
	UNIT_ADD_RELATIVE(angstrom, angstroms, nanometer, 0.1)
}

namespace units {

	class Time;
	class Velocity;

	class Length : public Unit<double, _units_private::dim_length> {
		public:
		explicit constexpr Length(const double& _val = 0) : Unit(_val) {}

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
		friend Length operator*(const Velocity&, const Time&);
	};
	typedef Length Distance;
	typedef Length Position;

	// Literals

	// Base unit
	GENERATE_LITERALS(Length, meter, meters, m)

	// SI prefix units
	GENERATE_LITERALS_SIPREFIXES(Length, meter, meters, m)

	// Non-SI units
	GENERATE_LITERALS(Length, foot, feet, ft)
	GENERATE_LITERALS(Length, yard, yards, yd)
	GENERATE_LITERALS(Length, inch, inches, in)
	GENERATE_LITERALS(Length, mile, miles, mi)
	GENERATE_LITERALS(Length, nautical_mile, nautical_miles, nmi)
	GENERATE_LITERALS(Length, astronomical_unit, astronomical_units, au)
	GENERATE_LITERALS(Length, light_year, light_years, ly)
	GENERATE_LITERALS(Length, parsec, parsecs, pc)
	GENERATE_LITERALS(Length, angstrom, angstroms, ang)
}