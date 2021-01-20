// Copyright 2018-19 Eric Fedosejevs

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/physics/forces/property.h"

cProperty::cProperty(const std::string& tmpName)
	: name(tmpName)
{}

std::string cProperty::getName() const {
	return name;
}