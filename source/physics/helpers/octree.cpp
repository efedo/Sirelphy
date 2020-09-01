// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/vector/vector_3d.h"
#include "Sirelphy/source/physics/helpers/octree.h"

cOctreeMember::cOctreeMember(const cVector3D& tmpPosition, cOctree* tmpOwner)
	: position(tmpPosition), octree(tmpOwner)
{
	if (octree)	octree->add(this); 
}

cOctreeMember::~cOctreeMember() {
	if (octree) octree->remove(this);
}

cVector3D cOctreeMember::getPosition() const {
	return position; 
}

void cOctreeMember::setPosition(const cVector3D& newPosition) {
	position = newPosition;
	if (octant)	getOwnerOctree()->remove(this);
	getOwnerOctree()->add(this);
}

cOctant::cOctant(cOctant* const tmpParentPtr, const cVector3D& lowBound, const cVector3D& highBound)
	: parent(tmpParentPtr), boundingBox(lowBound, highBound)
{
	splitpoint = (lowBound + highBound) / 2.0;
	directMembers = new std::set<cOctreeMember*>;
}

cOctant::~cOctant()
{
	if (directMembers) {
		// Tell any direct members that they are no longer owned by this octant
		for (std::set<cOctreeMember*>::iterator it = directMembers->begin(); it != directMembers->end(); ++it) {
			(*it)->setOctant(0);
		}

		delete directMembers;
	}

	for (unsigned int i = 0; i != 8; ++i) {
		if (children[i]) {
			delete children[i];
			children[i] = 0;
		}
	}
}

void cOctant::_add(cOctreeMember* const newMember) {

	// Subdivide if too many direct members already
	if (!isSubdivided) {
		if (!directMembers) throw_line("Octree direct member vector not accessible");
		if (directMembers->size() == maxMembersBeforeSubdivision) _subdivide();
	}

	// If it is subdivided, add to subdivision, otherwise add as direct member
	if (isSubdivided) {
		cVector3D newMemberPosition = newMember->getPosition();
		size_t i = 0;
		if (newMemberPosition.x() > splitpoint.x()) i += 4;
		if (newMemberPosition.y() > splitpoint.y()) i += 2;
		if (newMemberPosition.z() > splitpoint.z()) i += 1;
		children[i]->_add(newMember);
		_indirectMemberAdded();
	}
	else {
		if (!directMembers) throw_line("Octree direct member vector not available");
		directMembers->insert(newMember);
		newMember->setOctant(this);
	}
}

void cOctant::_subdivide() {
	if (isSubdivided) throw_line("Already subdivided");

	cVector3D lowBound = boundingBox.getLowerBound();
	cVector3D highBound = boundingBox.getLowerBound();

	children[0] = new cOctant(this, lowBound, splitpoint);
	children[1] = new cOctant(this, { lowBound.x(), lowBound.y(), highBound.z() }, splitpoint);
	children[2] = new cOctant(this, { lowBound.x(), highBound.y(), lowBound.z() }, splitpoint);
	children[3] = new cOctant(this, { lowBound.x(), highBound.y(), highBound.z() }, splitpoint);
	children[4] = new cOctant(this, { highBound.x(), lowBound.y(), lowBound.z() }, splitpoint);
	children[5] = new cOctant(this, { highBound.x(), lowBound.y(), highBound.z() }, splitpoint);
	children[6] = new cOctant(this, { highBound.x(), highBound.y(), lowBound.z() }, splitpoint);
	children[7] = new cOctant(this, splitpoint, highBound);

	isSubdivided = true;

	// Re-add direct members to subdivisions
	std::set<cOctreeMember*>* oldMemberVectorPtr = directMembers;
	directMembers = 0;

	if (oldMemberVectorPtr) {
		// Tell any direct members that they are no longer owned by this octant, move to childern
		for (std::set<cOctreeMember*>::iterator it = oldMemberVectorPtr->begin(); it != oldMemberVectorPtr->end(); ++it) {
			_add(*it);
		}

		delete oldMemberVectorPtr;
	}
}

void cOctant::_remove(cOctreeMember* const memberToRemove) {
	// If not subdivided, try to remove directly
	if (!isSubdivided) {
		if (!directMembers) throw_line("Could not access direct member set");
		if (directMembers->count(memberToRemove)) {
			directMembers->erase(memberToRemove);
			memberToRemove->setOctant(0);
			if (parent) parent->_indirectMemberRemoved();
		}
		else {
			throw_line("Member not found");
		}
	}
	else {
		throw_line("Tried to remove direct member from subdivided octant");
	}
}

cOctree::cOctree(const cVector3D& lowerBound, const cVector3D& upperBound)
: cOctant(0, lowerBound, upperBound)
{
}

void cOctree::add(cOctreeMember* const newMember) {
	//Check if within bounds
	if (!boundingBox.contains(newMember->getPosition())) {
		throw_line("New member is outside bounds of octree");
	}
	_add(newMember);
}

void cOctree::remove(cOctreeMember* const memberToRemove) {
	if (!memberToRemove) throw_line("Trying to remove non-existent member");
	try {
		cOctant* containingOctant = memberToRemove->getOctant();
		containingOctant->_remove(memberToRemove);
		memberToRemove->setOctant(0);
	}
	catch (...) {
		RETHROW("Could not remove member from supposed containing octant (containing octant pointer not properly updated?");
		// If you are so inclined, you could implement a back-up search for the member here based on its location
	}
}

void cOctant::_indirectMemberRemoved() {
	--indirectMemberCount;
	if (indirectMemberCount < minimumMembersBeforeCollapse) _collapse();
}

void cOctant::_indirectMemberAdded() {
	++indirectMemberCount;
}

void cOctant::_collapse() {
	std::cout << "Should collapse octant here\n";

	if (!isSubdivided) return; // Nothing to do, already collapsed

	// Declare not subdivided
	isSubdivided = false;

	// Promote members from each child and then delete child

	for (unsigned int i = 0; i != 8; ++i) {
		if (children[i]) {
			children[i]->_promoteMembers();
			delete children[i];
			children[i] = 0;
		}
	}
	indirectMemberCount = 0;
}

void cOctant::_promoteMembers() {
	if (directMembers) {
		// Tell any direct members that they are no longer owned by this octant, add them to parent
		for (std::set<cOctreeMember*>::iterator it = directMembers->begin(); it != directMembers->end(); ++it) {
			(*it)->setOctant(0);
			parent->_add(*it);
		}
		delete directMembers;
		directMembers = 0;
	}
}