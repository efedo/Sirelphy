// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Utilogeny/source/exceptions.h"
#include "Sirelphy/source/physics/universe/universe.h"
#include "Sirelphy/source/physics/forces/forces.h"
#include "Sirelphy/source/physics/objects/origin.h"
#include "Sirelphy/source/physics/objects/particleclass.h"
#include "Sirelphy/source/physics/objects/particle.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/special/vector_length.h"
#include "Sirelphy/source/physics/forces/gravity.h"
#include "Sirelphy/source/physics/forces/property.h"

enum class tForceClass : unsigned int { space = 0, spacetime = 1};

cUniverse::cUniverse()
	: _origin(new cOrigin)
{
	//_setupTernaryPhotonSystem();
}

cUniverse::~cUniverse() {
	if (_origin) delete _origin;
}


uint8_t cUniverse::getDimensions() const {
	return _dimensions;
}

cOrigin* cUniverse::getOrigin() const {
	return _origin;
}

double cUniverse::getMaxVelocity() const {
	return _maxVelocity;
}

/// Gets frame velocity at the given position
cGravityTensor cUniverse::getGravity(const cVectorLength3 &) const {
	cGravityTensor gravityTensor(_dimensions);
	gravityTensor.forcefield.dim(0) = 0.0;
	gravityTensor.fieldvelocity.dim(0) = 0.0;
	return gravityTensor;
}

double cUniverse::getTickLength() const {
	return ticklength;
}

void cUniverse::addProperty(const std::string & propName) {
	_addProperty(propName);
}

cProperty * cUniverse::_addProperty(const std::string & propName) {
	// If already added, throw, otherwise add
	if (properties.count(propName)) throw_line("Already added property with this name");
	cProperty * newProp = new cProperty(propName);
	properties.emplace(propName, newProp);
	return newProp;
}

cParticleClass * cUniverse::_addParticleClass(const std::string & className) {
	// If already added, throw, otherwise add
	if (pclasses.count(className)) throw_line("Already added particle class with this name");
	cParticleClass * newClass = new cParticleClass(className, this);
	pclasses.emplace(className, newClass);
	return newClass;
}

cForce * cUniverse::_addForce(const std::string & propNameA, const std::string & propNameB, const std::string& propNameBInertial, const double & newScaleFactor, const unsigned int & newOrder) {
	if (_getForce(propNameA, propNameB)) throw_line("Cannot re-add relationship");

	if (propNameA.empty() || propNameB.empty()) throw_line("Cannot add force for missing properties");

	// If not, create a new relationship and add it to the map
	cProperty * propA = _getProperty(propNameA);
	cProperty * propB = _getProperty(propNameB);
	cProperty * propBInertial = 0; 
	if (propNameBInertial.size()) {
		propBInertial = _getProperty(propNameBInertial);
	}

	return _addForce(propA, propB, propBInertial, newScaleFactor, newOrder);
}

cForce * cUniverse::_addForce(cProperty * propA, cProperty * propB, cProperty* propBInertial, const double & newScaleFactor, const unsigned int & newOrder) {

	if (!(propA || propB)) throw_line("Passed empty pointer");

	// First add force to forcelist
	cForce * newForce = new cForce(this, propA, propB, propBInertial, newScaleFactor, newOrder);
	forces.emplace(propA, std::map<cProperty *, cForce *>());
	forces.at(propA).emplace(propB, newForce);

	// Update the particle interaction cheat sheets (speeds up force calculations)
	_updatePClassForceLists(newForce);

	return newForce;
}

void cUniverse::addForce(const std::string & propNameA, const std::string & propNameB, const std::string& propNameBInertial, const double & newScaleFactor, const unsigned int & newOrder) {
	_addForce(propNameA, propNameB, propNameBInertial, newScaleFactor, newOrder);
}

void cUniverse::_updatePClassForceListsAll() {
	// Loop through forces and update lists]]
	for (std::map<cProperty *, std::map<cProperty *, cForce *>>::iterator it = forces.begin(); it != forces.end(); ++it) {
		for (std::map<cProperty *, cForce *>::iterator itdest = it->second.begin(); itdest != it->second.end(); ++itdest) {
			_updatePClassForceLists(itdest->second);
		}
	}
}

void cUniverse::_updatePClassForceLists(cForce * newForce) {

	// Make a list of particle classes that are sources of this force, and classes that are destinations of this force 
	std::list<cParticleClass *> sourceclasses;
	std::list<cParticleClass *> destclasses;

	cProperty * propA = newForce->getSourceProperty();
	cProperty * propB = newForce->getDestProperty();

	// Then look through particle classes, find those classes with property A or B
	for (std::map<std::string, cParticleClass *>::iterator it = pclasses.begin(); it != pclasses.end(); ++it) {
		// Check if this class has the originating force property
		if (it->second->getPropertyVal(propA)) {
			sourceclasses.push_back(it->second);
		}
		if (it->second->getPropertyVal(propB)) {
			destclasses.push_back(it->second);
		}
	}

	// Inform classes of relevant forces
	for (std::list<cParticleClass *>::iterator itsource = sourceclasses.begin(); itsource != sourceclasses.end(); ++itsource) {
		for (std::list<cParticleClass *>::iterator itdest = destclasses.begin(); itdest != destclasses.end(); ++itdest) {
			(*itsource)->addOriginatingForce((*itdest), newForce);
		}
	}
}

cProperty * cUniverse::_getProperty(const std::string & propName) const {
	if (properties.count(propName)) return properties.at(propName);
	return 0;
}

cParticleClass * cUniverse::_getParticleClass(const std::string & className) const {
	if (pclasses.count(className)) return pclasses.at(className);
	return 0;
}

cForce * cUniverse::_getForce(const std::string & propNameA, const std::string & propNameB) const {

	cProperty * propA = _getProperty(propNameA);
	cProperty * propB = _getProperty(propNameB);

	return _getForce(propA, propB);
}

cForce * cUniverse::_getForce(cProperty * propA, cProperty * propB) const {

	if (!(propA || propB)) throw_line("Passed empty pointer");

	// Check if this relationship already exists
	if (forces.count(propA)) {
		if (forces.at(propA).count(propB)) {
			return forces.at(propA).at(propB);
		}
	}
	return 0;
}

cParticle * cUniverse::_addParticle(const std::string & tmpClassName) {
	return _addParticle(_getParticleClass(tmpClassName));
}

cParticle * cUniverse::_addParticle(cParticleClass * particleclass) {
	if (!(particleclass)) throw_line("Passed empty pointer");
	cParticle * newParticle = new cParticle(this, _origin, particleclass);
	particles.push_back(newParticle);
	return newParticle;
}

void cUniverse::setupStandardModel() {

	// Add particle properties
	cProperty* propMass = _addProperty("mass"); // units?
	cProperty* propPositiveCharge = _addProperty("positive_charge"); // units?
	cProperty* propNegativeCharge = _addProperty("negative_charge"); // units?

	// Add forces
	_addForce(propPositiveCharge, propPositiveCharge, propMass, 1.0, 2); // Positive charge repels positive charge
	_addForce(propNegativeCharge, propNegativeCharge, propMass, 1.0, 2); // Negative charge repels negative charge
	_addForce(propPositiveCharge, propNegativeCharge, propMass, -1.0, 2); // Positive charge attracts negative charge
	_addForce(propPositiveCharge, propNegativeCharge, propMass, -1.0, 2); // Negative charge attracts positive charge
	_addForce(propMass, propMass, propMass, -0.1, 2); // Mass attracts mass (gravity)

	// Weak nuclear
	// Strong nuclear
	// Magnetic??? (or emergent?)

	// Add particle classes
	cParticleClass* class_electron = _addParticleClass("electron");
	class_electron->setProperty(propNegativeCharge, 1.0);
	class_electron->setProperty(propMass, 0.02);

	cParticleClass* class_proton = _addParticleClass("proton");
	class_proton->setProperty(propNegativeCharge, 1.0);
	class_proton->setProperty(propMass, 1.0);

	cParticleClass* class_neutron = _addParticleClass("neutron");
	//class_proton->setProperty(propNegativeCharge, 1.0);
	class_proton->setProperty(propMass, 1.0);

	// Add compound particles

}

void cUniverse::_setupTernaryPhotonSystem(cParticle * & pA, cParticle * & pB1, cParticle * & pB2) {
	cProperty * propPhotonA = _addProperty("Photon A property");
	cProperty * propPhotonB = _addProperty("Photon B property");

	_addForce(propPhotonA, propPhotonB, 0, -7.07E-13, 2); // Photon particle A attracts particle B
	_addForce(propPhotonB, propPhotonA, 0, 1.59E-12, 3); // Photon particle B repels particle A

	cParticleClass * class_photonA = _addParticleClass("Photon particle A");
	class_photonA->setProperty(propPhotonA, 1.0);

	cParticleClass * class_photonB = _addParticleClass("Photon particle B");
	class_photonB->setProperty(propPhotonB, 1.0);

	pA = _addParticle(class_photonA);
	pA->setPosition(cVector3D(0, 1e-11, 0));

	pB1 = _addParticle(class_photonB);
	pB1->setPosition(cVector3D(1e-30, 0, 0));

	pB2 = _addParticle(class_photonB);
	pB2->setPosition(cVector3D(-1e-30, 0, 0));

	//std::ofstream physicsfile("physicsout.tsv", std::ofstream::trunc);

	//if (!physicsfile.good()) {
	//	std::cerr << "Could not open physics file.\n";
	//	return;
	//}

	//physicsfile << "t\tdB:B\tdA:Bave\tekA\tvA(m/s)\tvA(c)\n";

	//const unsigned int imax = 10000;
	//for (unsigned int i = 0; i != imax; ++i) {
	//	physicsfile << std::fixed << std::setprecision(20) << time << "\t";
	//	physicsfile << std::scientific << std::setprecision(3) << (pB1->getPosition() - pB2->getPosition()).magnitude() << "\t";
	//	physicsfile << std::scientific << std::setprecision(3) << (pA->getPosition() - 0.5 * (pB1->getPosition() + pB1->getPosition())).magnitude() << "\t";
	//	physicsfile << std::scientific << std::setprecision(3) << pA->getKinEnergy().magnitude() << "\t";
	//	physicsfile << std::scientific << std::setprecision(3) << pA->getVelocity().magnitude() << "\t";
	//	physicsfile << std::scientific << std::setprecision(10) << pA->getVelocity().magnitude() / _maxVelocity << "\n";
	//	
	//	if ((i < 1000) || (!(i % 1000))) {
	//		std::cout << "\rCompleted physics iteration " << i << " out of " << imax;
	//	}
	//	_calcImpulses();
	//	_advanceTime();
	//}
	std::cout << "\n";
}

// Can be significantly sped up, by e.g. caching how a given particle class affects another
// and by restricting which particles affect which others (by e.g. distance)
void cUniverse::_calcImpulses() {

	// Loop through each potential effector particle
	for (std::list<cParticle *>::iterator iteffector = particles.begin(); iteffector != particles.end(); ++iteffector) {

		// Loop through each potential affectee particle
		for (std::list<cParticle *>::iterator itaffected = particles.begin(); itaffected != particles.end(); ++itaffected) {
			
			// See if one particle affects the other
			(*iteffector)->tryAffecting(*itaffected);

		}
	}
}

void cUniverse::_advanceTime() {
	// Loop through each potential effector particle
	for (std::list<cParticle *>::iterator it = particles.begin(); it != particles.end(); ++it) {
		(*it)->calcVelocityAndMove();
	}

	time += ticklength;
}