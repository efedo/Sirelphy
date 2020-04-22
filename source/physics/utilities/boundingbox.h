// Copyright 2018-20 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"

template <uint8_t ND>

class cBoundingBox {
public:
	cBoundingBox(const cVector<ND> lowerBound, const cVector<ND> upperBound)
		: _lowerBound(lowerBound), _upperBound(upperBound) 
	{
		// Fix out of order bounds
		

	}

	bool contains(const cVector<ND>& point) { ; }
	//bool contains(const cSolid & object) { ; }
	//bool surrounds(const);
	//bool surrounds(const cSolid & object);
	//bool surroundedBy()
protected:
	uint8_t				_dimensions = ND;
	cVector<ND>			_lowerBound;
	cVector<ND> 		_upperBound;
};

// Make specializations for 2d/3d