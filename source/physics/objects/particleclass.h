// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/unitlib/unitlib.h"

using namespace mass;

class cUniverse;

class cParticleClass {
public:
	/* constructor */			cParticleClass(const std::string&, cUniverse*);
	void						setMass(const QMass &); // Mass is a universal property separate from others
	const QMass					getMass() const;
	void						setProperty(cProperty *, const double &);
	void						setProperty(const std::string &, const double &);
	double						getPropertyVal(cProperty *);
	void						addOriginatingForce(cParticleClass *, cForce *);
	std::set<cForce *> *		getForcesToOtherClass(cParticleClass *);
private:
	QMass						_mass = 1;
	std::map<cProperty *, 
		double>					propertyVals;
	cUniverse *					_owner = 0;
	std::string					_name = "Unnamed particle class";
	std::map<cParticleClass *, 
		std::set<cForce *>>		appliedForces;
};