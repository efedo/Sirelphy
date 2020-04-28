// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/unitlib.h"
#include "Utilogeny/source/exceptions.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"

// 2 dimensional vector specialization interface
// cannot have any data members (must be able to up-cast from base
// with appropriate number of dimensions)
class cVector2D : public cVector<2> {
public:
	//cVector2D();
	cVector2D(const double&, const double&);
	cVector2D& operator=(const cVector<2>&);
	inline double& x() const { return dim(0); };
	inline double& y() const { return dim(1); };
};
