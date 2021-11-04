// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/objects/object.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/vector/special/vector_length.h"
#include "Sirelphy/source/core/physics/vector/special/vector_velocity.h"
#include "Sirelphy/source/core/physics/objects/frame.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"

//class cParticleSystem;
class cParticleClass;
class cUniverse;

class cParticle : public cObject {
public:
	cParticle(cUniverse * const, cFrame* const, cParticleClass* const);
	cParticleClass *			getClass();
	void						tryAffecting(cParticle *);
	//void						provideKinEnergy(cVectorND);

	// Friend functions
	friend units::QLength		distance(const cParticle&, const cParticle&);
	//friend double				distance_spacetime(const cParticle&, const cParticle&);
	friend double				rel_velocity(const cParticle&, const cParticle&);

private:
	cParticleClass *			_class = 0;
};

