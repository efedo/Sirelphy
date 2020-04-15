// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/units/energy.h"
#include "Sirelphy/source/unitlib/units/mass.h"
#include "Sirelphy/source/unitlib/units/velocity.h"

namespace energy {

	mass::QMass QEnergy::convertToMass() const {
		return mass::QMass(val);
	}

	QEnergy getKineticEnergy(const mass::QMass& _mass, const velocity::QVelocity& _vel) {
		const double dbl_mass = getRaw(_mass);// _mass.getRaw();
		const double dbl_vel = getRaw(_vel);
		return energy::QEnergy(0.5 * dbl_mass * dbl_vel * dbl_vel);
	}
}

//constexpr energy::QEnergy energy::getKineticEnergy(const mass::QMass& _mass, const velocity::QVelocity& _vel) {
//	return energy::QEnergy(5.0);
//	//const double dbl_mass = getRaw(_mass);// _mass.getRaw();
//	//const double dbl_vel = getRaw(_vel);
//	//return energy::QEnergy(0.5 * dbl_mass * dbl_vel * dbl_vel);
//}

//constexpr energy::QEnergy energy::getKineticEnergy(const mass::QMass& _mass, const velocity::QVelocity& _vel) {
//	const double dbl_mass = getRaw(_mass);// _mass.getRaw();
//	const double dbl_vel = getRaw(_vel);
//	return energy::QEnergy(0.5 * dbl_mass * dbl_vel * dbl_vel);
//}