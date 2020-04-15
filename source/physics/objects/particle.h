// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/objects/object.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/special/vector_length.h"
#include "Sirelphy/source/physics/vector/special/vector_velocity.h"
#include "Sirelphy/source/physics/objects/frame.h"
#include "Sirelphy/source/unitlib/unitlib.h"

//class cParticleSystem;
class cParticleClass;
class cUniverse;

using namespace length;
using namespace unittime;
using namespace energy;
using namespace mass;
using namespace velocity;

class cParticle : public cObject {
public:
	cParticle(cUniverse * const, cFrame* const, cParticleClass* const);
	cParticleClass *			getClass();
	void						tryAffecting(cParticle *);
	//void						provideKinEnergy(cVectorND);

	// Friend functions
	friend QLength				distance(const cParticle&, const cParticle&);
	//friend double				distance_spacetime(const cParticle&, const cParticle&);
	friend double				rel_velocity(const cParticle&, const cParticle&);

private:
	cParticleClass *			_class = 0;
};

