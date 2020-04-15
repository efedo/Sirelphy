// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/objects/frame.h"
#include "Sirelphy/source/physics/objects/origin.h"

cFrame::cFrame(cFrame* tmpRel)
	: _relativeTo(tmpRel) {
	if (tmpRel == this) throw_line("Cannot make non-origin frames relative to self");
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

//QTime cFrame::getPositionTime()	const { 
//	return _position.t(); 
//}

cVectorVelocity3 cFrame::getVelocity() const { 
	return _velocity;
}

QVelocity cFrame::getVelocityMagnitude() const { 
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

//void cFrame::setPositionTime(const QTime& _time) { 
//	_position.t() = _time; 
//}

//void cFrame::setTime(const QTime& _time) { 
//	setPositionTime(_time);
//}

void cFrame::setVelocity(const cVectorVelocity3& _newVel) { 
	_velocity = _newVel; 
}