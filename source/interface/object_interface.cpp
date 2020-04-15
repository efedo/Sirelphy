// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/interface/object_interface.h"
#include "Sirelphy/source/physics/objects/object.h"

cObjectInterface::cObjectInterface(cObject* tmpObject)
	: _object(tmpObject) {}

void cObjectInterface::getPosition(double& posX, double& posY, double& posZ) {
	posX = _object->getPosition().x().in_meters();
	posY = _object->getPosition().y().in_meters();
	posZ = _object->getPosition().z().in_meters();
}

void cObjectInterface::getVelocity(double& velX, double& velY, double& velZ) {
	velX = _object->getVelocity().x().getRaw();
	velY = _object->getVelocity().y().getRaw();
	velZ = _object->getVelocity().z().getRaw();
}

void cObjectInterface::getVelocityMagnitudeMPS(double& velMPS) {
	velMPS = _object->getVelocity().magnitude().getRaw();
}

void cObjectInterface::getVelocityMagnitudeC(double& velC) {
	velC = _object->getVelocity().magnitude().relToC();
}