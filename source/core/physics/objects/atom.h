// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/universe/universe.h"
#include "Sirelphy/source/core/physics/objects/particleclass.h"
#include "Sirelphy/source/core/physics/forces/forces.h"

class Element : public cParticleClass {
	std::string name;
	uint16_t num_protons;
	uint16_t num_electrons;
	uint16_t num_neutrons;
};

Element[] = 
{{"Hydrogen", 1, 1, 0 }
 {"Deuterium", 1, 1, 1 }
 {"Helium", 2, 2, 0 } }

class Atom : public cParticle {
	Element* element;
};