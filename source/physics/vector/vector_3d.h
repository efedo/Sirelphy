// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/unitlib.h"
#include "Utilogeny/source/exceptions.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"

// 3 dimensional vector specialization
// cannot have any data members (must be able to up-cast from base
// with appropriate number of dimensions)
class cVector3D : public cVector<3> {
public:
	cVector3D();
	cVector3D(const double&, const double&, const double&);
	inline double& x() const { return dim(0); };
	inline double& y() const { return dim(1); };
	inline double& z() const { return dim(2); };
};
