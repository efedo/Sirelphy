// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/units/energy.h"
#include "Sirelphy/source/core/unitlib/units/mass.h"
#include "Sirelphy/source/core/unitlib/units/length.h"
#include "Sirelphy/source/core/unitlib/units/time.h"
#include "Sirelphy/source/core/unitlib/units/velocity.h"

using namespace velocity;

QUnit<double, dim_velocity> operator*(const QVelocity& lhs, const QVelocity& rhs) {
	return lhs.getBaseUnit();// *rhs.getBaseUnit();
}

QVelocity operator/(const length::QLength& lhs, const unittime::QTime& rhs) {
	return QVelocity(0);// lhs.getBaseUnit();// / rhs.getBaseUnit();
}