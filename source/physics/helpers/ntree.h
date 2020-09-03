// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/helpers/ntree.decl.h"

using cQuadtree = cNtree<2>;
using cOctree = cNtree<3>;

template <uint8_t D>
cNtreeMember<D>::cNtreeMember(const cVector<D>& tmpPosition, cNtree<D>* tmpOwner)
	: position(tmpPosition), ntree(tmpOwner)
{
	if (ntree) ntree->add(this);
}

template <uint8_t D>
cNtreeMember<D>::~cNtreeMember() {
	if (ntree) ntree->remove(this);
}

template <uint8_t D>
cVector<D> cNtreeMember<D>::getPosition() const {
	return position;
}

template <uint8_t D>
void cNtreeMember<D>::setPosition(const cVector<D>& newPosition) {
	position = newPosition;
	if (ntant)	getOwnerNtree()->remove(this);
	getOwnerNtree()->add(this);
}

template <uint8_t D>
cNtant<D>::cNtant(cNtant<D>* const tmpParentPtr, const cVector<D>& lowBound, const cVector<D>& highBound)
	: parent(tmpParentPtr), boundingBox(lowBound, highBound)
{
	splitpoint = (lowBound + highBound) / 2.0;
	directMembers = new std::set<cNtreeMember*>;
}

template <uint8_t D>
cNtant<D>::~cNtant()
{
	if (this->directMembers) {
		// Tell any direct members that they are no longer owned by this ntant
		for (typename std::set<cNtreeMember<D>*>::iterator it = this->directMembers->begin(); it != this->directMembers->end(); ++it) {
			(*it)->setNtant(0);
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

template <uint8_t D>
void cNtant<D>::_add(cNtreeMember<D>* const newMember) {

	// Subdivide if too many direct members already
	if (!isSubdivided) {
		if (!directMembers) throw_line("Ntree direct member vector not accessible");
		if (directMembers->size() == maxMembersBeforeSubdivision) _subdivide();
	}

	// If it is subdivided, add to subdivision, otherwise add as direct member
	if (isSubdivided) {
		cVector<D> newMemberPosition = newMember->getPosition();
		size_t i = 0;
		for (uint8_t dim = D; dim != 0; --dim) {
			if (newMemberPosition.dim(dim) > splitpoint.dim(dim)) i += pwrtwo(dim);
		}
		//if (newMemberPosition.x() > splitpoint.x()) i += 4;
		//if (newMemberPosition.y() > splitpoint.y()) i += 2;
		//if (newMemberPosition.z() > splitpoint.z()) i += 1;
		children[i]->_add(newMember);
		_indirectMemberAdded();
	}
	else {
		if (!directMembers) throw_line("Ntree direct member vector not available");
		directMembers->insert(newMember);
		newMember->setNtant(this);
	}
}

template <uint8_t D>
void cNtant<D>::_subdivide() {
	if (isSubdivided) throw_line("Already subdivided");

	cVector<D> lowBound = boundingBox.getLowerBound();
	cVector<D> highBound = boundingBox.getLowerBound();
	cVector<D> exteriorBound;
	for (size_t n = 0; D != pwrtwo(D); ++n) {
		// for each child ntant, need to build up correct exterior vector
		for (uint8_t dim = 0; dim != D; dim) {
			constexpr size_t dimpow = pwrtwo(dim);
			if (n && dimpow) { // high
				exteriorBound.dim(D - dim) = highBound.dim(dim);
			}
			else { // low
				exteriorBound.dim(D - dim) = lowBound.dim(dim);
			}
		}
		children[n] = new cNtant(this, exteriorBound, splitpoint);
	}

	//children[0] = new cNtant(this, lowBound, splitpoint);
	//children[1] = new cNtant(this, { lowBound.x(), lowBound.y(), highBound.z() }, splitpoint);
	//children[2] = new cNtant(this, { lowBound.x(), highBound.y(), lowBound.z() }, splitpoint);
	//children[3] = new cNtant(this, { lowBound.x(), highBound.y(), highBound.z() }, splitpoint);
	//children[4] = new cNtant(this, { highBound.x(), lowBound.y(), lowBound.z() }, splitpoint);
	//children[5] = new cNtant(this, { highBound.x(), lowBound.y(), highBound.z() }, splitpoint);
	//children[6] = new cNtant(this, { highBound.x(), highBound.y(), lowBound.z() }, splitpoint);
	//children[7] = new cNtant(this, splitpoint, highBound);

	isSubdivided = true;

	// Re-add direct members to subdivisions
	std::set<cNtreeMember<D>*>* oldMemberVectorPtr = directMembers;
	directMembers = 0;

	if (this->oldMemberVectorPtr) {
		// Tell any direct members that they are no longer owned by this ntant, move to childern
		for (typename std::set<cNtreeMember<D>*>::iterator it = this->oldMemberVectorPtr->begin(); it != this->oldMemberVectorPtr->end(); ++it) {
			_add(*it);
		}

		delete oldMemberVectorPtr;
	}
}

template <uint8_t D>
void cNtant<D>::_remove(cNtreeMember<D>* const memberToRemove) {
	// If not subdivided, try to remove directly
	if (!isSubdivided) {
		if (!directMembers) throw_line("Could not access direct member set");
		if (directMembers->count(memberToRemove)) {
			directMembers->erase(memberToRemove);
			memberToRemove->setNtant(0);
			if (parent) parent->_indirectMemberRemoved();
		}
		else {
			throw_line("Member not found");
		}
	}
	else {
		throw_line("Tried to remove direct member from subdivided ntant");
	}
}

template <uint8_t D>
cNtree<D>::cNtree(const cVector<D>& lowerBound, const cVector<D>& upperBound)
	: cNtant(0, lowerBound, upperBound)
{}

template <uint8_t D>
void cNtree<D>::add(cNtreeMember<D>* const newMember) {
	//Check if within bounds
	if (!this->boundingBox.contains(newMember->getPosition())) {
		throw_line("New member is outside bounds of ntree");
	}
	_add(newMember);
}

template <uint8_t D>
void cNtree<D>::remove(cNtreeMember<D>* const memberToRemove) {
	if (!memberToRemove) throw_line("Trying to remove non-existent member");
	try {
		cNtant* containingNtant = memberToRemove->getNtant();
		containingNtant->_remove(memberToRemove);
		memberToRemove->setNtant(0);
	}
	catch (...) {
		RETHROW("Could not remove member from supposed containing ntant (containing ntant pointer not properly updated?");
		// If you are so inclined, you could implement a back-up search for the member here based on its location
	}
}

template <uint8_t D>
void cNtant<D>::_indirectMemberRemoved() {
	--indirectMemberCount;
	if (indirectMemberCount < minimumMembersBeforeCollapse) _collapse();
}

template <uint8_t D>
void cNtant<D>::_indirectMemberAdded() {
	++indirectMemberCount;
}

template <uint8_t D>
void cNtant<D>::_collapse() {
	std::cout << "Should collapse ntant here\n";

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

template <uint8_t D>
void cNtant<D>::_promoteMembers() {
	if (this->directMembers) {
		// Tell any direct members that they are no longer owned by this ntant, add them to parent
		for (typename std::set<cNtreeMember<D>*>::iterator it = this->directMembers->begin(); it != this->directMembers->end(); ++it) {
			(*it)->setNtant(0);
			parent->_add(*it);
		}
		delete this->directMembers;
		this->directMembers = 0;
	}
}