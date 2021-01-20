// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/units/mass.h"
#include "Sirelphy/source/core/unitlib/units/energy.h"

energy::QEnergy mass::QMass::convertToEnergy() const {
	return energy::QEnergy(val);
}