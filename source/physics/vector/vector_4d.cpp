// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_4d.h"


// 4D specific operations

cVector4D::cVector4D() {

}

cVector4D::cVector4D(const double& tmpX, const double& tmpY, const double& tmpZ, const double& tmpT)
{
	x() = tmpX;
	y() = tmpY;
	z() = tmpZ;
	t() = tmpT;
}

cVector4D::cVector4D(const cVector<4>& tmpVec) {
	*this = *static_cast<const cVector4D*>(&tmpVec);
}

const cVector4D& cVector4D::operator=(const cVector<4>& rhs) {
	return *(static_cast<const cVector4D*>(&rhs));
}

cVector4D& cVector4D::operator=(cVector<4>& rhs) {
	return *(static_cast<cVector4D*>(&rhs));
}