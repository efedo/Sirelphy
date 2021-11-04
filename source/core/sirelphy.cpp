// Sirelphy.cpp : Defines the functions for the static library.
//

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"
#include "Sirelphy/source/core/interface/universe_interface.h"
#include "Sirelphy/source/core/physics/universe/universe.h"

// Exists only to ensure that required templates for all interfaces are instantiated
int instantiateTemplates()
{
	cUniverse universe;
	cUniverseInterface uni_interface;

	return 1;
}

// TODO: This is an example of a library function
int fnSirelphy()
{

//	instantiateTemplates();

	units::QLength mylength;
	mylength.setRaw(10000000000000000);
	double lenm = mylength.in_m();
	std::cout << "length in m: " << lenm;

	units::QLength myotherlength;

	using namespace units;
	myotherlength = 10.56_meters;

	return 5;
}