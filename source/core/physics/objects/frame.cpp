// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/objects/frame.h"
#include "Sirelphy/source/core/physics/objects/origin.h"

cFrame::cFrame(cFrame* tmpRel)
	: _relativeTo(tmpRel) {
	if (tmpRel == this) throwl("Cannot make non-origin frames relative to self");
}; // Makes a frame relative to another

cFrame::cFrame(cOrigin* origin) 
: _relativeTo(origin)
{}

///////////////////////////////////////////////////////////////////////////////////////
// Get position/time																 //
///////////////////////////////////////////////////////////////////////////////////////

//cVectorLength3Time1 cFrame::getPositionSpaceTime() const { 
//	return _position; 
//}

cVectorLength3 cFrame::getPositionSpace() const { 
	return _position; 
}

//Time cFrame::getPositionTime()	const { 
//	return _position.t(); 
//}

cVectorVelocity3 cFrame::getVelocity() const { 
	return _velocity;
}

units::Velocity cFrame::getVelocityMagnitude() const {
	return _velocity.magnitude(); 
}

///////////////////////////////////////////////////////////////////////////////////////
// Set position/time																 //
///////////////////////////////////////////////////////////////////////////////////////

//void cFrame::setPositionSpaceTime(const cVectorLength3Time1& _spaceTime) { 
//	_position = _spaceTime; 
//}

void cFrame::setPositionSpace(const cVectorLength3& _space) { 
	_position = _space; 
}

//void cFrame::setPositionTime(const Time& _time) { 
//	_position.t() = _time; 
//}

//void cFrame::setTime(const Time& _time) { 
//	setPositionTime(_time);
//}

void cFrame::setVelocity(const cVectorVelocity3& _newVel) { 
	_velocity = _newVel; 
}