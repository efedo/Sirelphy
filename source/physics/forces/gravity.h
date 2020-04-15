// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"

class cGravityTensor {
public:
	cVector3D fieldvelocity;
	cVector3D forcefield;
	cGravityTensor(const uint8_t &);
};