// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/universe/universe.h"
#include "Sirelphy/source/core/physics/objects/particle.h"
#include "Sirelphy/source/core/physics/objects/object.h"
#include "Sirelphy/source/core/interface/universe_interface.h"
#include "Sirelphy/source/core/interface/object_interface.h"

cUniverseInterface::cUniverseInterface() 
	: universe(new cUniverse)
{}

cUniverseInterface::~cUniverseInterface()
{
	if (universe) delete universe;
}

void cUniverseInterface::advanceTime(const double&) {
	universe->_advanceTime();
}