// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/universe/universe.h"
#include "Sirelphy/source/physics/objects/particleclass.h"
#include "Sirelphy/source/physics/forces/forces.h"
#include "Utilogeny/source/exceptions.h"

cParticleClass::cParticleClass(const std::string & tmpName, cUniverse * tmpOwner)
	: _name(tmpName), _owner(tmpOwner)
{}

void cParticleClass::setMass(const QMass & newmass) {
	_mass = newmass;
}

const QMass cParticleClass::getMass() const {
	return _mass;
}

void cParticleClass::setProperty(cProperty * propToSet, const double & newVal) {
//	TRY

	if (!newVal) {
		throw_line("Cannot zero out a force using set property -- need to use remove command");
	}

	if (propertyVals.count(propToSet)) {
		propertyVals.at(propToSet) = newVal;
	}
	else {
		propertyVals.emplace(propToSet, newVal);
	}

	// Be sure to update all lists of effected particles 
	_owner->_updatePClassForceListsAll();

//	CODE_FAILED_VOCAL_RETHROW("Failed to set particle property by pointer");

	// Change to 0 should result in erasure and all sorts of stuff
}

double cParticleClass::getPropertyVal(cProperty * prop) {
	if (propertyVals.count(prop)) {
		return propertyVals.at(prop);
	}
	return 0.0;
}

void cParticleClass::addOriginatingForce(cParticleClass * target, cForce * newforce) {

	if (!(target || newforce)) {
		throw_line("Either the force or target were undefined");
	}

	// Check that this class has the force's affector property, and that the target class has the force's affected property
	cProperty * sourceProp = newforce->getSourceProperty();
	cProperty * destProp = newforce->getDestProperty();

	if (!(sourceProp || destProp)) {
		throw_line("One of the force properties was undefined");
	}

	if (!(getPropertyVal(sourceProp) || getPropertyVal(destProp))) {
		throw_line("Either the source or destination class being assigned this force did not contain the required property");
	}

	if (!appliedForces.count(target)) {
		appliedForces.emplace(target, std::set<cForce *>());
	}

	appliedForces.at(target).emplace(newforce);
}

std::set<cForce *> * cParticleClass::getForcesToOtherClass(cParticleClass * otherclass) {
	if (appliedForces.count(otherclass)) return &appliedForces.at(otherclass);
	return 0;
}