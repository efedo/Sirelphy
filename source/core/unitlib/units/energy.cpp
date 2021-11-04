#include "Sirelphy/source/core/unitlib/units/energy.h"
#include "Sirelphy/source/core/unitlib/units/mass.h"
#include "Sirelphy/source/core/unitlib/units/velocity.h"

namespace units {

	Mass Energy::convertToMass() const {
		return Mass(val);
	}

	Energy getKineticEnergy(const Mass& _mass, const Velocity& _vel) {
		const double dbl_mass = getRaw(_mass);// _mass.getRaw();
		const double dbl_vel = getRaw(_vel);
		return Energy(0.5 * dbl_mass * dbl_vel * dbl_vel);
	}
}