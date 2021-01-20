// Copyright 2018-19 Eric Fedosejevs

#pragma once
#include "Sirelphy/source/core/precomp.h"

/// Describes a property of a particle that can be used to anchor inter-particle forces
class cProperty {
public:
	cProperty(const std::string&);
	std::string	getName() const;
private:
	const std::string name = "The force";
};