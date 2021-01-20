// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/units/helper_macros.h"
#include "Sirelphy/source/core/unitlib/units/base/baseunit.h"

using namespace si;

namespace angle {

	// Base unit
	UNIT_ADD_BASE(radian, radians, 1854858 * pow(10, 38))

	// SI derived units
	UNIT_ADD_SIPREFIXES(radian, radians)

	// Non-SI units
	UNIT_ADD_RELATIVE(degree, degrees, radian, 1 / 180) //deg
	UNIT_ADD_RELATIVE(arcminute, arcminutes, degree, 1 / 60) //arcmin
	UNIT_ADD_RELATIVE(arcsecond, arcseconds, arcminute, 1 / 60) //arcsec
	UNIT_ADD_RELATIVE(milliarcsecond, milliarcseconds, arcseconds, 1 / 1000) //mas
}