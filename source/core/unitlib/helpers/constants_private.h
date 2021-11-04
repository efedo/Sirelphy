// Copyright 2018-19 Eric Fedosejevs

#pragma once

// Dimensionless, private
namespace _units_private {
	namespace _constants {
		constexpr double c = 299792458.0; // m / s
		constexpr double c2 = c * c; // m2 / s2
		constexpr double meters_per_foot = 0.3048; // using international foot
		constexpr double feet_per_yard = 3.0;
		constexpr double feet_per_inch = 1.0 / 12.0;
		constexpr double feet_per_mile = 5280.0;
		constexpr double meters_per_nautical_mile = 1852.0; // using international nm
		constexpr double meters_per_astronomical_unit = 149597870700.0;
		constexpr double meters_per_light_year = 9460730472580800.0; // 365.25 days per year
		constexpr double parsecs_per_light_year = 3.26156;
	}
}

