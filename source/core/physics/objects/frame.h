// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/vector/special/vector_length.h"
#include "Sirelphy/source/core/physics/vector/special/vector_velocity.h"

class cFrame;
class cOrigin;

class cFrame {
public:
	cFrame(cFrame*);
	cFrame() = delete;

	// Get position/time
//	cVectorLength3Time1			getPositionSpaceTime()		const;
	cVectorLength3				getPositionSpace()			const;
//	QTime						getPositionTime()			const;
	cVectorVelocity3			getVelocity()				const;
	units::QVelocity			getVelocityMagnitude()		const;

	// Set position/time
//	void						setPositionSpaceTime(const cVectorLength3Time1&);
	void						setPositionSpace(const cVectorLength3&);
//	void						setPositionTime(const QTime&);
//	void						setTime(const QTime&);
	void						setVelocity(const cVectorVelocity3&);

protected:
	friend class cOrigin;
	cFrame(cOrigin*);
	cFrame* const				_relativeTo = 0;
	cVectorLength3				_position;
	cVectorVelocity3			_velocity;
//	QTime						_time;
//	cVectorOrientation3			_orientation;
//	cVectorRotation3			_rotation;
	uint16_t					_level = 0; // How many levels frame is removed from origin
};
