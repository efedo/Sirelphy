// Copyright 2018-20 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Utilogeny/source/core/randomnumbers.h"

template <uint8_t D>
class cBoundingBox {
public:

	cBoundingBox() {}
	cBoundingBox(const cVector<D> tmpLowerBound, const cVector<D> tmpUpperBound)
		: _lowerBound(tmpLowerBound), _upperBound(tmpUpperBound)
	{
		_fixOutOfOrderBounds();
	}

	cVector<D>			getLowerBound() const { return _lowerBound; }
	cVector<D>			getUpperBound() const { return _upperBound; }

	void				setLowerBound(const cVector<D> & newLowerBound) {
		_lowerBound = newLowerBound;
		_fixOutOfOrderBounds();
	}


	void				setUpperBound(const cVector<D>& newUpperBound) {
		_upperBound = newUpperBound;
		_fixOutOfOrderBounds();
	}

	bool				contains(const cVector<D>& point) const { 
		for (int i = 0; i != D; ++i) {
			if (point.dim(i) < _lowerBound.dim(i)) return false;
			if (point.dim(i) > _upperBound.dim(i)) return false;
		}
		return true;
	}

	cVector<D>			getRandomPositionInside() const {
		cVector<D> randomPosition;
		for (int i = 0; i != D; ++i) {
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
		for (int i = 0; i != D; ++i) {
			if (_lowerBound.dim(i) > _upperBound.dim(i)) {
				double high = _lowerBound.dim(i);
				_lowerBound.dim(i) = _upperBound.dim(i);
				_upperBound.dim(i) = high;
			}
		}
	}
	uint8_t				_dimensions = D;
	cVector<D>			_lowerBound;
	cVector<D> 		_upperBound;
};

class cBoundingBox3D : public cBoundingBox<3> {
public:

	cBoundingBox3D(const cVector3D& lowBound, const cVector3D& highBound) 
		: cBoundingBox<3>(lowBound, highBound)
	{ }

	cVector3D			getRandomPositionInside() const {
		return cBoundingBox<3>::getRandomPositionInside();
	}

	cVector3D			getLowerBound() const { return cBoundingBox<3>::getLowerBound(); }
	cVector3D			getUpperBound() const { return cBoundingBox<3>::getUpperBound(); }
};

// Make specializations for 2d/3d