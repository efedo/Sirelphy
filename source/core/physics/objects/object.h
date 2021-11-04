// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/objects/frame.h"
#include "Sirelphy/source/core/physics/helpers/bounding.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"

class cFrame;
class cUniverse;

class cObject {
public:
	cObject (cUniverse* const, cFrame* const);
	~cObject();

	// Set initial dynamics
	void						setPosition(const cVectorLength3&);
	void						setVelocity(const cVectorVelocity3&);
	void						changeReference(cFrame* const);			// Will be very complicated to implement....

	// Get mass/energy
	units::QEnergy				getEnergyRest()						const;
	units::QEnergy				getEnergyKinetic()					const;
	units::QEnergy				getEnergyTotal()					const;
	units::QMass				getMassRest()						const;
	units::QMass				getMassEffective()					const;

	// Relativity
	cFrame *					getReference()						const;
	cUniverse*					getUniverse()						const;
	double						getClockSpeedFractional()			const;
	cVectorLength3				getPosition()						const;
	cVectorVelocity3			getVelocity()						const;
	double						getVelocityFractional()				const;
	double						getVelocitySpacetimeFractional()	const; /// Should always be 1.0;
		// All objects are always moving at a constant relative speed when you sum their 
		// relative movement in time and space
	double						getBeta()							const;
	double						getGammaFromVel()					const;
	double						getGammaFromTime()					const;
	double						getTimeLikeness()					const;
	double						getSpaceLikeness()					const;

	// Update functions
	void						tick(const units::QDuration &);
	void						provideKinEnergy(cVector3D);
	void						calcVelocityAndMove();

	// Two-object functions
	units::QLength				distance(const cObject&) const;
	double						rel_velocity(const cObject&) const;
	cVector<3>					direction(const cObject&) const; // Unit direction from first vector to second vector

	// Friend functions
	friend units::QLength		distance(const cObject&, const cObject&);
	friend cVector<3>			direction(const cObject&, const cObject&); // Unit direction from first vector to second vector
	//friend double				distance_spacetime(const cParticle&, const cParticle&);
	friend double				rel_velocity(const cObject&, const cObject&);

protected:
	friend class cOrigin; // Origin of the universe is friend of all objects

	// Owning universe
	cUniverse* const			_universe = 0;

	// Proper properties (reference-frame-independent properties) 
	units::QTime				_age = units::QTime(0);
	units::QMass				_restMass = units::QMass(0);

	// Relative properties (reference-frame-dependent)
	cFrame * const				_relativeTo = 0;
	cVectorLength3				_position;
	cVectorVelocity3			_velocity;
	cVector3D					_ekinetic; // Directional kinetic energy relative to reference frame
	double						_clockSpeed; // 0 to 1, fractional, relative to reference frame

	//cVectorOrientation3		_orientation;
	//cVectorRotation3			_rotation;
};