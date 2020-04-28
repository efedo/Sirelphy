// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_4d.h"


// 4D specific operations
cVector4D::cVector4D()
{}

cVector4D::cVector4D(const double& tmpX, const double& tmpY, const double& tmpZ, const double& tmpT)
{
	x() = tmpX;
	y() = tmpY;
	z() = tmpY;
	t() = tmpY;
}

cVector4D& cVector4D::operator=(const cVector<4>& rhs) {
	return rhs.get4D();
}