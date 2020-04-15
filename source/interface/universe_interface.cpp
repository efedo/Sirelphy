// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Utilogeny/source/exceptions.h"
#include "Sirelphy/source/physics/universe/universe.h"
#include "Sirelphy/source/physics/objects/particle.h"
#include "Sirelphy/source/physics/objects/object.h"
#include "Sirelphy/source/interface/universe_interface.h"
#include "Sirelphy/source/interface/object_interface.h"

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

void cUniverseInterface::launchTernaryPhoton(cObjectInterface*& oA, cObjectInterface*& oB1, cObjectInterface*& oB2) {
	cParticle* pA =0;
	cParticle* pB1 = 0;
	cParticle* pB2 = 0;
	universe->_setupTernaryPhotonSystem(pA, pB1, pB2);
	oA = new cObjectInterface(pA);
	oB1 = new cObjectInterface(pA);
	oB2 = new cObjectInterface(pA);
}