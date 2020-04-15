// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/si_prefixes.h"
#include "Sirelphy/source/unitlib/units/helper_macros.h"
#include "Sirelphy/source/unitlib/units/base/baseunit.h"
#include "Sirelphy/source/unitlib/units/base/dimension_fundamentals.h"
#include "Sirelphy/source/unitlib/constants.h"

using namespace si;

namespace energy {
	class QEnergy;
}

namespace mass {

	// Base unit
	UNIT_ADD_BASE(joule_mass, joule_masses, 1.0)
	UNIT_ADD_RELATIVE(gram, grams, joule_mass, c2 / 1000)

	// SI derived units
	UNIT_ADD_SIPREFIXES(gram, grams)

	// Non-SI units
	UNIT_ADD_RELATIVE(solar_mass, solar_masses, kilogram, 1.98847e30) //t
	UNIT_ADD_RELATIVE(metric_ton, metric_tons, kilogram, 1000) //t
	UNIT_ADD_RELATIVE(pound, pounds, kilogram, 45359237 / 100000000) // //lb
	UNIT_ADD_RELATIVE(long_ton, long_tons, pound, 2240) // ln_t
	UNIT_ADD_RELATIVE(short_ton, short_tons, pound, 2000) //sh_t
	UNIT_ADD_RELATIVE(stone, stones, kilogram, 1000) //st
	UNIT_ADD_RELATIVE(ounce, ounces, pound, 1 / 16) //oz
	UNIT_ADD_RELATIVE(carat, carats, milligram, 200) //ct
	UNIT_ADD_RELATIVE(dalton, daltons, gram, 1.66053906660e-24) // Da
	UNIT_ADD_RELATIVE(kilodalton, kilodaltons, dalton, 1000) // kDa
	UNIT_ADD_RELATIVE(electronvolt_mass, electronvolts_mass, gram, 1.782662e-33) // eVm

	class QMass : public QUnit<double, dim_mass> {
	public:
		constexpr QMass(const double& _val = 0) : QUnit(_val) {}

		// Functions
		energy::QEnergy convertToEnergy() const;
	};
}