// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/universe/universe.h"

struct UniverseGenerator {
	static cUniverse* createStandardModelAtomic();
	static cUniverse* createStandardModelFull();
	static cUniverse* createTernaryPhotonSystem();
};