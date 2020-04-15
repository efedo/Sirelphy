// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/si_prefixes.h"
#include "Sirelphy/source/unitlib/units/helper_macros.h"
#include "Sirelphy/source/unitlib/units/base/baseunit.h"
#include "Sirelphy/source/unitlib/units/base/dimension_fundamentals.h"

using namespace si;

namespace mass { class QMass; }

namespace velocity { class QVelocity; }

namespace energy {

	// Base unit
	UNIT_ADD_BASE(joule, joules, 1.0)

		//// SI derived units
		//UNIT_ADD_SIPREFIXES(gram, grams)

		//// Non-SI units
		//UNIT_ADD_RELATIVE(solar_mass, solar_masses, kilogram, 1.98847 * pow(10, 30)) //t
		//UNIT_ADD_RELATIVE(metric_ton, metric_tons, kilogram, 1000) //t

		class QEnergy : public QUnit<double, dim_energy> {
		public:
			constexpr QEnergy(const double& _val = 0) : QUnit(_val) {}

			// Functions
			mass::QMass convertToMass() const;

			constexpr friend QEnergy operator+(const QEnergy lhs, const QEnergy rhs) {
				return QEnergy(lhs.val + rhs.val);
			}

			constexpr friend QEnergy operator-(const QEnergy lhs, const QEnergy rhs) {
				return QEnergy(lhs.val - rhs.val);
			}
	};

	//constexpr QEnergy getKineticEnergy(const mass::QMass&, const velocity::QVelocity&);
	QEnergy getKineticEnergy(const mass::QMass&, const velocity::QVelocity&);
};

