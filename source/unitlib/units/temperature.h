// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/si_prefixes.h"
#include "Sirelphy/source/unitlib/units/helper_macros.h"
#include "Sirelphy/source/unitlib/units/baseunit.h"

using namespace si;

namespace temperature {

	// Base unit
	UNIT_ADD_BASE(kelvin, kelvin, 1854858 * pow(10, 38)) // K

	// SI derived units
	UNIT_ADD_SIPREFIXES(kelvin, kelvin)

	// Non-SI units
	//UNIT_ADD(temperature, celsius, celsius, degC, unit<std::ratio<1>, kelvin, std::ratio<0>, std::ratio<27315, 100>>)
	//UNIT_ADD(temperature, fahrenheit, fahrenheit, degF, unit<std::ratio<5, 9>, celsius, std::ratio<0>, std::ratio<-160, 9>>)

}