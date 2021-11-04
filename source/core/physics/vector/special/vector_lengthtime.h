// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/units.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/vector/special/vector_length.h"

//
//class cVectorLength3Time1 {
//protected:
//	cVectorLength3 _space;
//	Time _time;
//public:
//	inline Length x() const { return _space.x(); }
//	inline Length y() const { return _space.y(); }
//	inline Length z() const { return _space.z(); }
//	inline Time t() const { return Time(_time); }
//	inline cVectorLength3 getSpacePosition() const { return _space; }
//
//	Length getLengthSpace() const { return Length(_space.magnitude()); }
//	Time getLengthTime() const { return (_time); }
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
//	void setTimePosition(const Time& tmp_t) { setTimePosition(tmp_t.getRaw()); }
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
//	cVectorLength3Time1(const Length& _x, const Length& _y, const Length& _z, const Time& _t)
//		: cVectorLength3Time1(_x.getRaw(), _y.getRaw(), _z.getRaw(), _t.getRaw())
//	{}
//
//	cVectorLength3Time1(const cVectorLength3& _vecSpace, const Time& _t)
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