// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/vector/vector.h"

class cGravityTensor {
public:
	cVector3D fieldvelocity;
	cVector3D forcefield;
	cGravityTensor(const uint8_t &);
};