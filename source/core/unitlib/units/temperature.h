// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/unitlib/units/base.h"

using namespace si;

namespace _units_private {
	UNIT_ADD_BASE(kelvin, kelvin, 1.0) // K
	UNIT_ADD_SIPREFIXES(kelvin, kelvin)
}

namespace units {

	template<>
	class Unit<double, _units_private::dim_temperature> : public _units_private::_Unit<double, _units_private::dim_temperature> {
	public:
		constexpr Unit(const double _val = 0) : _Unit(_val) {}
		constexpr Unit(const Unit& rhs) : _Unit(rhs.val) {}

		// Unit member functions
		GENERATE_MEMBER_FUNCTIONS(kelvin, kelvin, K)
		GENERATE_MEMBER_FUNCTIONS_SIPREFIXES(kelvin, kelvin, K)

		//UNIT_ADD(temperature, celsius, celsius, degC, unit<std::ratio<1>, kelvin, std::ratio<0>, std::ratio<27315, 100>>)
		//UNIT_ADD(temperature, fahrenheit, fahrenheit, degF, unit<std::ratio<5, 9>, celsius, std::ratio<0>, std::ratio<-160, 9>>)
	};

	// Literals
	GENERATE_LITERALS(Temperature, kelvin, kelvin, K)
	GENERATE_LITERALS_SIPREFIXES(Temperature, kelvin, kelvin, K)
}