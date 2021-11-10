// Copyright 2018-19 Eric Fedosejevs

#include <string>

class cUniverse;
class cObjectInterface;

class cUniverseInterface {
public:
	cUniverseInterface();
	void advanceTime(const double&);
	~cUniverseInterface();
private:
	cUniverse* const universe = 0;
};