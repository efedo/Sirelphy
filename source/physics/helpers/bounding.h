// Copyright 2018-20 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"
#include "Utilogeny/source/randomnumbers.h"

template <uint8_t ND>

class cBoundingBox {
public:

	cBoundingBox() {}
	cBoundingBox(const cVector<ND> tmpLowerBound, const cVector<ND> tmpUpperBound)
		: _lowerBound(tmpLowerBound), _upperBound(tmpUpperBound)
	{
		_fixOutOfOrderBounds();
	}

	cVector<ND>			getLowerBound() const { return _lowerBound; }
	cVector<ND>			getUpperBound() const { return _upperBound; }

	void				setLowerBound(const cVector<ND> & newLowerBound) {
		_lowerBound = newLowerBound;
		_fixOutOfOrderBounds();
	}


	void				setUpperBound(const cVector<ND>& newUpperBound) {
		_upperBound = newUpperBound;
		_fixOutOfOrderBounds();
	}

	bool				contains(const cVector<ND>& point) const { 
		for (int i = 0; i != ND; ++i) {
			if (point.dim(i) < _lowerBound.dim(i)) return false;
			if (point.dim(i) > _upperBound.dim(i)) return false;
		}
		return true;
	}

	cVector<ND>			getRandomPositionInside() const {
		cVector<ND> randomPosition;
		for (int i = 0; i != ND; ++i) {
			randomPosition.dim(i) = globals::mersenneTwister.randomDouble(_lowerBound.dim(i), _upperBound.dim(i));
		}
		return randomPosition;
	}

	//bool contains(const cSolid & object) { ; }
	//bool surrounds(const);
	//bool surrounds(const cSolid & object);
	//bool surroundedBy()
protected:
	void				_fixOutOfOrderBounds() {
		// Fix out of order bound
		for (int i = 0; i != ND; ++i) {
			if (_lowerBound.dim(i) > _upperBound.dim(i)) {
				double high = _lowerBound.dim(i);
				_lowerBound.dim(i) = _upperBound.dim(i);
				_upperBound.dim(i) = high;
			}
		}
	}
	uint8_t				_dimensions = ND;
	cVector<ND>			_lowerBound;
	cVector<ND> 		_upperBound;
};

class cBoundingBox3D : public cBoundingBox<3> {
public:

	cBoundingBox3D(const cVector3D& lowBound, const cVector3D& highBound) 
		: cBoundingBox<3>(lowBound, highBound)
	{ }

	cVector3D			getRandomPositionInside() const {
		return cBoundingBox<3>::getRandomPositionInside().get3D();
	}

	cVector3D			getLowerBound() const { return cBoundingBox<3>::getLowerBound().get3D(); }
	cVector3D			getUpperBound() const { return cBoundingBox<3>::getUpperBound().get3D(); }
};

// Make specializations for 2d/3d