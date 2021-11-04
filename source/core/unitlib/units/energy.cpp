#include "Sirelphy/source/core/unitlib/units/energy.h"
#include "Sirelphy/source/core/unitlib/units/mass.h"
#include "Sirelphy/source/core/unitlib/units/velocity.h"

namespace units {

	QMass QEnergy::convertToMass() const {
		return QMass(val);
	}

	QEnergy getKineticEnergy(const QMass& _mass, const QVelocity& _vel) {
		const double dbl_mass = getRaw(_mass);// _mass.getRaw();
		const double dbl_vel = getRaw(_vel);
		return QEnergy(0.5 * dbl_mass * dbl_vel * dbl_vel);
	}
}