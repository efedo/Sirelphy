// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/unitlib.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"

template <class T>
class cVectorUnit3 {
public:
	cVectorUnit3() {}

	cVectorUnit3(const cVector3D& tmpVec)
		: vec3d_backend(tmpVec) {}

	cVectorUnit3(const cVector<3>& tmpVec)
		: vec3d_backend(tmpVec.get3D()) {}

	cVectorUnit3(const double& tmp_x, const double& tmp_y, const double& tmp_z)
		: vec3d_backend(tmp_x, tmp_y, tmp_z) {}

	cVectorUnit3(const T& tmp_x, const T& tmp_y, const T& tmp_z)
		: cVectorUnit3<T>(tmp_x.getRaw(), tmp_y.getRaw(), tmp_z.getRaw()) {}

	cVectorUnit3(const cVectorUnit3<T>& rhs)
		: cVectorUnit3(rhs.vec3d_backend)
	{}


	inline T x() const { return T(vec3d_backend.x()); }
	inline T y() const { return T(vec3d_backend.y()); }
	inline T z() const { return T(vec3d_backend.z()); }

	cVector3D& getRaw() {
		return vec3d_backend;
	}

	// Spatial distance from first vector to second vector
	friend T distance(const cVectorUnit3<T>& lhs, const cVectorUnit3<T>& rhs) {
		return T(distance(lhs.vec3d_backend, rhs.vec3d_backend));
	}

	inline T magnitude() const {
		return T(vec3d_backend.magnitude());
	}

	// Unit direction from first vector to second vector
	friend cVectorUnit3<T> direction(const cVectorUnit3<T>& lhs, const cVectorUnit3<T>& rhs) {
		return cVectorUnit3<T>(lhs.vec3d_backend.direction(rhs.vec3d_backend).get3D());
	}

	// Normal angle from first vector to second vector (0 to 1)
	friend double angle(const cVectorUnit3<T>& lhs, const cVectorUnit3<T>& rhs) {
		return angle(lhs.vec3d_backend, rhs.vec3d_backend);
	}

	cVectorUnit3<T>& operator=(const cVectorUnit3<T>& rhs)
	{
		vec3d_backend = rhs.vec3d_backend;
		return *this;
	}

	friend cVectorUnit3<T> operator+(const cVectorUnit3<T>& lhs, const cVectorUnit3<T>& rhs)
	{
		return cVectorUnit3<T>(lhs.vec3d_backend + rhs.vec3d_backend);
	}

private:
	cVector3D vec3d_backend;
};


