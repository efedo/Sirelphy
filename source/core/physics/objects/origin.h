// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/objects/frame.h"

// The central reference, i.e. the location of the big bang/origin of the universe
// Only frame that is relative exclusively to itself
class cOrigin : public cFrame 
{
private:
	friend class cUniverse;
	cOrigin()
		: cFrame(this)
	{}
};

