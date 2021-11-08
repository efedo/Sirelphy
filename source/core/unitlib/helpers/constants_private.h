// Copyright 2018-19 Eric Fedosejevs

#pragma once

// Dimensionless, private
namespace _units_private {
	constexpr double sqr(double a) {
		return a * a;
	}

	constexpr double power(double a, std::size_t n) {
		return n == 0 ? 1 : sqr(power(a, n / 2)) * (n % 2 == 0 ? 1 : a);
	}

	namespace _constants {
		constexpr double c = 299792458.0; // m s-1 [L1 T-1]
		constexpr double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
		constexpr double vacuum_permitivity = 8.854187812813 / power(10, 12); // F m-1 farads per meter

		// electron charge:mass ratio (or electron rest mass)

		// Below are just conversion factors due to arbitrary molar definitions of amounts
		constexpr double avogadro = 6.02214076 * _units_private::power(10, 23); // units1 mol-1 [A1 A-1]
		constexpr double coulomb = 6.2415090744607626077762409809304 * _units_private::power(10, 18); // units1 C-1 [A1 Q-1]
		constexpr double faraday = avogadro / coulomb;// C mol-1 [Q A-1] 
	}
}

