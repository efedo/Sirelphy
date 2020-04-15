// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/unitlib.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/special/vector_length.h"

using namespace length;
using namespace unittime;
using namespace velocity; 
//
//class cVectorLength3Time1 {
//protected:
//	cVectorLength3 _space;
//	QTime _time;
//public:
//	inline QLength x() const { return _space.x(); }
//	inline QLength y() const { return _space.y(); }
//	inline QLength z() const { return _space.z(); }
//	inline QTime t() const { return QTime(_time); }
//	inline cVectorLength3 getSpacePosition() const { return _space; }
//
//	QLength getLengthSpace() const { return QLength(_space.magnitude()); }
//	QTime getLengthTime() const { return (_time); }
//
//	double getLengthSpacetime(const cVectorLength3Time1 &) {
//		const double lSpace = getLengthSpace().getRaw();
//		const double lTime = getLengthTime();
//		return (sqrt(lSpace * lSpace + lTime * lTime)); // Not sure if this should be squared
//	}
//
//	void setSpacePosition(const cVectorLength3& _vecSpace) {
//		_x = _vecSpace._x;
//		_y = _vecSpace.y().getRaw();
//		_z = _vecSpace.z().getRaw();
//	}
//	void setTimePosition(const double& tmp_t) { _t = tmp_t; }
//	void setTimePosition(const QTime& tmp_t) { setTimePosition(tmp_t.getRaw()); }
//
//
//
//
//
//
//	friend double distanceSpace(const cVectorLength3Time1& vec1, const cVectorLength3Time1& vec2) {
//		cVector3D dif;
//		dif.x = vec1.x - vec2.x;
//		dif.y = vec1.y - vec2.y;
//		dif.z = vec1.z - vec2.z;
//
//		return sqrt((dif.x * dif.x) + (dif.y * dif.y) + (dif.z * dif.z));
//	}
//
//
//
//
//
//	cVectorLength3Time1() {}
//
//	cVectorLength3Time1(const double& tmp_x, const double& tmp_y, const double& tmp_z, const double& tmp_t) 
//		: cVector4D(tmp_x, tmp_y, tmp_z, tmp_t)
//	{}
//
//	cVectorLength3Time1(const QLength& _x, const QLength& _y, const QLength& _z, const QTime& _t)
//		: cVectorLength3Time1(_x.getRaw(), _y.getRaw(), _z.getRaw(), _t.getRaw())
//	{}
//
//	cVectorLength3Time1(const cVectorLength3& _vecSpace, const QTime& _t)
//		: cVectorLength3Time1(_vecSpace.x().getRaw(), _vecSpace.y().getRaw(), _vecSpace.z().getRaw(), _t.getRaw())
//	{}
//
//	constexpr cVectorLength3Time1& operator=(const cVectorLength3Time1& rhs)
//	{
//		_x = rhs._x;
//		_y = rhs._y;
//		_z = rhs._z;
//		_t = rhs._t;
//		return *this;
//	}
//};