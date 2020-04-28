// Copyright 2018-20 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_nd.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"
#include "Sirelphy/source/physics/helpers/bounding.h"

class cOctant;
class cOctree;

class cOctreeMember {
public:
	cOctreeMember(const cVector3D &);
	~cOctreeMember();
	cVector3D getPosition() const;
	void setPosition(const cVector3D& newPosition);
	virtual cOctree * getOwnerOctree() const { throw_line_overridden; }
private:
	friend class cOctant;
	friend class cOctree;
	void setOctant(cOctant* const newOctant) { octant = newOctant; }
	cOctant* getOctant() const { return octant; }
	cOctant* octant = 0;
	cVector3D position;
};

class cOctant {
public:
	cOctant(cOctant* const, const cVector3D&, const cVector3D&);
	~cOctant();
protected:
	friend class cOctree;
	void _add(cOctreeMember* const);
	void _subdivide();
	void _remove(cOctreeMember* const);
	void _indirectMemberAdded();
	void _indirectMemberRemoved();
	void _collapse();
	void _promoteMembers();
	cOctant* parent = 0;
	cVector3D splitpoint;
	cBoundingBox3D boundingBox;
	bool isSubdivided = false;
	cOctant* children[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	std::set<cOctreeMember*> * directMembers;
	uint64_t indirectMemberCount = 0;
	uint64_t maxMembersBeforeSubdivision = 24;
	uint64_t minimumMembersBeforeCollapse = 8;
};

class cOctree : public cOctant {
public:
	cOctree(const cVector3D&, const cVector3D&);
	void add(cOctreeMember* const);
	void remove(cOctreeMember* const);
};