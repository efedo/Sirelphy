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

	template<>
	class Unit<double, _units_private::dim_energy> : public _units_private::_Unit<double, _units_private::dim_energy> {
		public:
		constexpr Unit(const double _val = 0) : _Unit(_val) {}
		constexpr Unit(const Unit& rhs) : _Unit(rhs.val) {}


		// Functions
		Mass convertToMass() const {
			throw;
			return Mass();
		}

		//constexpr friend Energy operator+(const Energy lhs, const Energy rhs) {
		//	return Energy(lhs.val + rhs.val);
		//}

		//constexpr friend Energy operator-(const Energy lhs, const Energy rhs) {
		//	return Energy(lhs.val - rhs.val);
		//}
	};

	// Literals
	GENERATE_LITERALS(Energy, joule, joules, j)
	GENERATE_LITERALS_SIPREFIXES(Energy, joule, joules, j)

	Energy getKineticEnergy(const Mass& _mass, const Velocity& _vel) {
		throw; // need to update due to change in base units
		//const double dbl_mass = getRaw(_mass);// _mass.getRaw();
		//const double dbl_vel = getRaw(_vel);
		//return Energy(0.5 * dbl_mass * dbl_vel * dbl_vel);
	}
};

