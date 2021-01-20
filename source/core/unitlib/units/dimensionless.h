// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/si_prefixes.h"
#include "Sirelphy/source/core/unitlib/units/helper_macros.h"
#include "Sirelphy/source/core/unitlib/units/baseunit.h"

using namespace si;

class QDimensionless : public QUnit<double, dim_none> {
public:
	constexpr QDimensionless(const double& _val = 0) : QUnit(_val) {}
};