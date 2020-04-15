// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/special/vector_length.h"
#include "Sirelphy/source/physics/objects/frame.h"

class cBoundingBox : public cFrame {
	cBoundingBox(const cFrame & tmpFrame) : cFrame(tmpFrame) {}
private:
	cVectorLength3 _boundingMins;
	cVectorLength3 _boundingMaxs;
};