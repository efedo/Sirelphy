// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/vector/special/vector_unit3d.h"

using namespace length;
using namespace unittime;
using namespace velocity;


typedef cVectorUnit3<QVelocity> cVectorVelocity3;

//class cVectorVelocity3 : public cVectorUnit3<QVelocity> {
//public:
//};