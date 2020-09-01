// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/universe/universe.h"
#include "Sirelphy/source/physics/objects/object.h"
#include "Sirelphy/source/physics/vector/special/vector_length.h"
#include "Sirelphy/source/physics/vector/special/vector_velocity.h"
#include "Sirelphy/source/unitlib/units/energy.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"
#include "Sirelphy/source/physics/objects/frame.h"
#include "Sirelphy/source/physics/forces/gravity.h"

cObject::cObject(cUniverse* const _tmpUniverse, cFrame* const _refFrame)
	: _universe(_tmpUniverse), _relativeTo(_refFrame)
{}

cObject::~cObject() {
}

///////////////////////////////////////////////////////////////////////////////////////
// Set initial dynamics																 //
///////////////////////////////////////////////////////////////////////////////////////

void cObject::setPosition(const cVectorLength3& tmpPos) {
	_position = tmpPos;
}

void cObject::setVelocity(const cVectorVelocity3& tmpVel) {
	_velocity = tmpVel;
}

///////////////////////////////////////////////////////////////////////////////////////
// Get mass/energy																	 //
///////////////////////////////////////////////////////////////////////////////////////

QEnergy cObject::getEnergyRest() const { 
	return _restMass.convertToEnergy(); 
}

QEnergy cObject::getEnergyKinetic() const {
	return energy::getKineticEnergy(getMassRest(), getVelocity().magnitude());
}

QEnergy cObject::getEnergyTotal() const {
	return getEnergyRest() + getEnergyKinetic();
}

QMass cObject::getMassRest() const { 
	return _restMass; 
};

QMass cObject::getMassEffective() const { 
	throw_line_not_implemented; 
}

///////////////////////////////////////////////////////////////////////////////////////
// Relativity    																	 //
///////////////////////////////////////////////////////////////////////////////////////

cUniverse* cObject::getUniverse() const {
	return _universe;
}

cFrame* cObject::getReference() const {
	return _relativeTo;
};

double cObject::getClockSpeedFractional() const {
	return _clockSpeed;
};

double cObject::getVelocityFractional() const {
	return _velocity.magnitude().relToC();
};

cVectorLength3 cObject::getPosition() const {
	return _position;
}

cVectorVelocity3 cObject::getVelocity() const {
	return _velocity;
};

double cObject::getBeta() const {
	return getVelocityFractional();
};

double cObject::getGammaFromVel() const {
	const double beta = getBeta();
	return 1.0 / (sqrt(1.0 - beta * beta));
};

double cObject::getGammaFromTime() const {
	// Based on amount of time contraction
	return getClockSpeedFractional();
};

/// Should always be 1.0
double cObject::getVelocitySpacetimeFractional() const {
	const double velocityTime = getClockSpeedFractional();
	const double velocitySpace = getVelocityFractional();
	return sqrt(velocityTime * velocityTime + velocitySpace * velocitySpace);
}

double cObject::getTimeLikeness() const {
	const double velocityTime = getClockSpeedFractional();
	return velocityTime * velocityTime;
}

double cObject::getSpaceLikeness() const {
	const double velocitySpace = getVelocityFractional();
	return velocitySpace * velocitySpace;
}

// Update functions
void cObject::tick(const QDuration&) {
	throw_line_not_implemented;
}

void cObject::provideKinEnergy(cVector3D addedImpulse) {
	_ekinetic += addedImpulse;
}

void cObject::calcVelocityAndMove() {

	// Gets frame velocity at the current position
	cGravityTensor gravity = _universe->getGravity(_position);

	// Gets the global max in-frame velocity
	const boost::multiprecision::cpp_bin_float_quad maxvel = _universe->getMaxVelocity();

	// Find the magnitude of the kinetic energy
	const boost::multiprecision::cpp_bin_float_quad ekinmag = _ekinetic.magnitude();
	if (!isfinite(_ekinetic.magnitude())) throw_line("Non-finite kinetic energy");

	// Calculate what the relative (in-frame) velocity should be based on ekinetic
	// Refer to eq. for kin eng in special relativity
	const boost::multiprecision::cpp_bin_float_quad gamma =
		((ekinmag) / ((maxvel * maxvel) * _restMass.getRaw())) + 1.0;
	const boost::multiprecision::cpp_bin_float_quad sqrtterm =
		1.0 - (1.0 / (gamma * gamma));
	const double relvel = (maxvel * sqrt(sqrtterm)).convert_to<double>();
	if (!isfinite(relvel)) throw_line("Non-finite relative velocity");

	// Get in-frame directional velocity
	cVector3D newVel = _ekinetic;
	newVel.scaleTo(relvel);

	//if (abs((_velocity.magnitude() - relvel) / relvel) > 0.1) {
	//	std::cerr << "Incorrect relativistic velocity result.\n";
	//}

	// Convert to global frame
	newVel += gravity.fieldvelocity;

	// Update position in global frame
	_position = _position + cVectorLength3(newVel);

	// Note that this is and the global velocity calculation are currently a cludge; 
	// do not fully account for relativistic effects (e.g. length contraction)
}

QLength cObject::distance(const cObject& objectB) const {
	// Check for same owner
	if (getUniverse() != objectB.getUniverse()) throw_line("Trying to get distances between objects in different universes");
	return QLength(0);
	//return QLength(distance(getPosition().getRaw(), objectB.getPosition().getRaw()));
}

QLength distance(const cObject& objectA, const cObject& objectB) {
	return objectA.distance(objectB);
}

// Unit direction from first vector to second vector
cVector<3> cObject::direction(const cObject& objectB) const {
	return getPosition().getRaw().direction(objectB.getPosition().getRaw());
}

// Unit direction from first vector to second vector
cVector<3> direction(const cObject& objectA, const cObject& objectB) {
	return objectA.direction(objectB);
}


double cObject::rel_velocity(const cObject& objectB) const {

	// Check for same owner
	if (getUniverse() != objectB.getUniverse()) throw_line("Trying to get relative velocity between objects in different universes")

	// Get unit direction from A to B
	cVector3D dirAtoB = direction(objectB);

	// Determine angle between velocity of A and direction from A to B and vice versa
	double angleVelAToB = angle(getVelocity().getRaw(), dirAtoB);
	double angleVelBToA = angle(objectB.getVelocity().getRaw(), -dirAtoB);

	// Calculate the movement towards or away from the other point
	double velAtoB = getVelocity().magnitude().getRaw() * cos(angleVelAToB);
	double velBtoA = objectB.getVelocity().magnitude().getRaw() * cos(angleVelBToA);

	return velAtoB + velBtoA;
}

double rel_velocity(const cObject& objectA, const cObject& objectB) {
	return objectA.rel_velocity(objectB);
}