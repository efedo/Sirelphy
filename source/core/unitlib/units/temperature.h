// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/units/helper_macros.h"
#include "Sirelphy/source/core/unitlib/units/baseunit.h"

using namespace si;

namespace _units_private {
	UNIT_ADD_BASE(kelvin, kelvin, 1854858 * pow(10, 38)) // K
	UNIT_ADD_SIPREFIXES(kelvin, kelvin)
	//UNIT_ADD(temperature, celsius, celsius, degC, unit<std::ratio<1>, kelvin, std::ratio<0>, std::ratio<27315, 100>>)
	//UNIT_ADD(temperature, fahrenheit, fahrenheit, degF, unit<std::ratio<5, 9>, celsius, std::ratio<0>, std::ratio<-160, 9>>)
}

namespace units {
}