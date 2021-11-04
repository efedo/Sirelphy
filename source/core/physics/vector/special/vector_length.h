// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/units.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/vector/special/vector_unit3d.h"

typedef cVectorUnit3<units::Length> cVectorLength3;

//class cVectorLength3 : public cVectorUnit3<Length> {
//public:
//	cVectorLength3() {}
//
//	cVectorLength3(const cVector3D& tmpVec)
//		: cVectorUnit3<Length>(tmpVec) {}
//
//	cVectorLength3(const double& tmp_x, const double& tmp_y, const double& tmp_z)
//		: cVectorUnit3<Length>(tmp_x, tmp_y, tmp_z) {}
//
//	cVectorLength3(const Length& tmp_x, const Length& tmp_y, const Length& tmp_z)
//		: cVectorUnit3<Length>(tmp_x.getRaw(), tmp_y.getRaw(), tmp_z.getRaw()) {}
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
//	cVectorLength3(const Length& tmp_x, const Length& tmp_y, const Length& tmp_z) 
//		: cVectorLength3(tmp_x.getRaw(), tmp_y.getRaw(), tmp_z.getRaw()) {}
//
//	inline Length x() const { return Length(vec3d_backend.x()); }
//	inline Length y() const { return Length(vec3d_backend.y()); }
//	inline Length z() const { return Length(vec3d_backend.z()); }
//
//	cVector3D& getRaw() {
//		return vec3d_backend;
//	}
//
//	// Spatial distance from first vector to second vector
//	friend Length distance(const cVectorLength3& lhs, const cVectorLength3& rhs) {
//		return Length(distance(lhs.vec3d_backend, rhs.vec3d_backend));
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

