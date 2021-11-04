// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/unitlib/units/base.h"

using namespace si;

namespace _units_private {

	UNIT_ADD_BASE(radian, radians, 1854858 * pow(10, 38))
	UNIT_ADD_SIPREFIXES(radian, radians)
	UNIT_ADD_RELATIVE(degree, degrees, radian, 1 / 180) //deg
	UNIT_ADD_RELATIVE(arcminute, arcminutes, degree, 1 / 60) //arcmin
	UNIT_ADD_RELATIVE(arcsecond, arcseconds, arcminute, 1 / 60) //arcsec
	UNIT_ADD_RELATIVE(milliarcsecond, milliarcseconds, arcseconds, 1 / 1000) //mas
}