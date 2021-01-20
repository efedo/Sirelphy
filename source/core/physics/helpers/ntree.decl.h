// Copyright 2018-20 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/physics/helpers/bounding.h"

constexpr size_t pwrtwo(uint8_t exponent) {
	return (size_t(1) << exponent);
}

template <uint8_t D>
class cNtant;

template <uint8_t D>
class cNtree;

template <uint8_t D>
class cNtreeMember {
public:
	cNtreeMember(const cVector<D>&, cNtree<D>*);
	~cNtreeMember();
	cVector<D> getPosition() const;
	void setPosition(const cVector<D>& newPosition);
	cNtree<D>* getOwnerNtree() const { return ntree; };
private:
	template <uint8_t D>
	friend class cNtant;
	template <uint8_t D>
	friend class cNtree;
	void setNtant(cNtant<D>* const newNtant) { ntant = newNtant; }
	cNtant<D>* getNtant() const { return ntant; }
	cNtant<D>* ntant = 0;
	cNtree<D>* ntree = 0;
	cVector<D> position;
};

template <uint8_t D>
class cNtant {
public:
	cNtant(cNtant<D>* const, const cVector<D>&, const cVector<D>&);
	~cNtant();
protected:
	template <uint8_t D>
	friend class cNtree;
	void _add(cNtreeMember<D>* const);
	void _subdivide();
	void _remove(cNtreeMember<D>* const);
	void _indirectMemberAdded();
	void _indirectMemberRemoved();
	void _collapse();
	void _promoteMembers();
	cNtant* parent = 0;
	cVector<D> splitpoint;
	cBoundingBox<D> boundingBox;
	bool isSubdivided = false;
	cNtant* children[pwrtwo(D)] = { 0 };
	std::set<cNtreeMember<D>*>* directMembers;
	uint64_t indirectMemberCount = 0;
	const uint64_t maxMembersBeforeSubdivision = 3 * pwrtwo(D);
	const uint64_t minimumMembersBeforeCollapse = pwrtwo(D);
};

template <uint8_t D>
class cNtree : public cNtant<D> {
public:
	cNtree(const cVector<D>&, const cVector<D>&);
	void add(cNtreeMember<D>* const);
	void remove(cNtreeMember<D>* const);
};