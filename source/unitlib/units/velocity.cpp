// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/units/energy.h"
#include "Sirelphy/source/unitlib/units/mass.h"
#include "Sirelphy/source/unitlib/units/length.h"
#include "Sirelphy/source/unitlib/units/time.h"
#include "Sirelphy/source/unitlib/units/velocity.h"

using namespace velocity;

QUnit<double, dim_velocity> operator*(const QVelocity& lhs, const QVelocity& rhs) {
	return lhs.getBaseUnit();// *rhs.getBaseUnit();
}

QVelocity operator/(const length::QLength& lhs, const unittime::QTime& rhs) {
	return QVelocity(0);// lhs.getBaseUnit();// / rhs.getBaseUnit();
}