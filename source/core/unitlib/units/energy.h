// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/unitlib/units/base.h"

using namespace si;

namespace _units_private {
	UNIT_ADD_BASE(joule, joules, 1.0)
	//UNIT_ADD_SIPREFIXES(gram, grams)
	//UNIT_ADD_RELATIVE(solar_mass, solar_masses, kilogram, 1.98847 * pow(10, 30)) //t
	//UNIT_ADD_RELATIVE(metric_ton, metric_tons, kilogram, 1000) //t
}

namespace units {

	class Mass;
	class Velocity;

	class Energy : public Unit<double, _units_private::dim_energy> {
	public:
		explicit constexpr Energy(const double& _val = 0) : Unit(_val) {}

		// Functions
		Mass convertToMass() const;

		constexpr friend Energy operator+(const Energy lhs, const Energy rhs) {
			return Energy(lhs.val + rhs.val);
		}

		constexpr friend Energy operator-(const Energy lhs, const Energy rhs) {
			return Energy(lhs.val - rhs.val);
		}
	};

	Energy getKineticEnergy(const Mass& _mass, const Velocity& _vel);
};

