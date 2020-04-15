// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/units/mass.h"
#include "Sirelphy/source/unitlib/units/energy.h"

energy::QEnergy mass::QMass::convertToEnergy() const {
	return energy::QEnergy(val);
}