// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_2d.h"


// 2D specific operations
cVector2D::cVector2D(const double& tmpX, const double& tmpY)
{
	x() = tmpX;
	y() = tmpY;
}
