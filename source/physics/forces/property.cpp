// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/physics/forces/property.h"

cProperty::cProperty(const std::string& tmpName)
	: name(tmpName)
{}

std::string cProperty::getName() const {
	return name;
}