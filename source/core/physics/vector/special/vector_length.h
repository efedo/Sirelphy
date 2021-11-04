// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/vector/special/vector_unit3d.h"

typedef cVectorUnit3<units::QLength> cVectorLength3;

//class cVectorLength3 : public cVectorUnit3<QLength> {
//public:
//	cVectorLength3() {}
//
//	cVectorLength3(const cVector3D& tmpVec)
//		: cVectorUnit3<QLength>(tmpVec) {}
//
//	cVectorLength3(const double& tmp_x, const double& tmp_y, const double& tmp_z)
//		: cVectorUnit3<QLength>(tmp_x, tmp_y, tmp_z) {}
//
//	cVectorLength3(const QLength& tmp_x, const QLength& tmp_y, const QLength& tmp_z)
//		: cVectorUnit3<QLength>(tmp_x.getRaw(), tmp_y.getRaw(), tmp_z.getRaw()) {}
//
//	cVectorLength3(const cVectorUnit3<T>& rhs)
//		: cVectorUnit3(rhs.vec3d_backend)
//	{}
//};

//class cVectorLength3 {
//public:
//	cVectorLength3() {}
//	cVectorLength3(const cVector3D & tmpVec)
//		: vec3d_backend(tmpVec) {}
//	cVectorLength3(const double& tmp_x, const double& tmp_y, const double& tmp_z)
//		: vec3d_backend(tmp_x, tmp_y, tmp_z) {}
//	cVectorLength3(const QLength& tmp_x, const QLength& tmp_y, const QLength& tmp_z) 
//		: cVectorLength3(tmp_x.getRaw(), tmp_y.getRaw(), tmp_z.getRaw()) {}
//
//	inline QLength x() const { return QLength(vec3d_backend.x()); }
//	inline QLength y() const { return QLength(vec3d_backend.y()); }
//	inline QLength z() const { return QLength(vec3d_backend.z()); }
//
//	cVector3D& getRaw() {
//		return vec3d_backend;
//	}
//
//	// Spatial distance from first vector to second vector
//	friend QLength distance(const cVectorLength3& lhs, const cVectorLength3& rhs) {
//		return QLength(distance(lhs.vec3d_backend, rhs.vec3d_backend));
//	}
//
//	// Unit direction from first vector to second vector
//	friend cVectorND direction(const cVectorLength3& lhs, const cVectorLength3& rhs) {
//		return direction(lhs.vec3d_backend, rhs.vec3d_backend);
//	}
//
//	// Normal angle from first vector to second vector (0 to 1)
//	friend double angle(const cVectorLength3& lhs, const cVectorLength3& rhs) {
//		return angle(lhs.vec3d_backend, rhs.vec3d_backend);
//	}
//
//private:
//	cVector3D vec3d_backend;
//};
//

