// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"


//// 3D specific operations

cVector3D::cVector3D() {

}

cVector3D::cVector3D(const double& tmpX, const double& tmpY, const double& tmpZ)
{
	x() = tmpX;
	y() = tmpY;
	z() = tmpZ;
}

cVector3D::cVector3D(const cVector<3>& tmpVec) {
	*this = *static_cast<const cVector3D*>(&tmpVec);
}

const cVector3D& cVector3D::operator=(const cVector<3>& rhs) {
	return *(static_cast<const cVector3D*>(&rhs));
}

cVector3D& cVector3D::operator=(cVector<3>& rhs) {
	return *(static_cast<cVector3D*>(&rhs));
}