// Sirelphy.cpp : Defines the functions for the static library.
//

#include "Sirelphy/source/precomp.h"
#include "Sirelphy/source/unitlib/unitlib.h"
#include "Sirelphy/source/interface/universe_interface.h"
#include "Sirelphy/source/physics/universe/universe.h"

using namespace length;

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

	QLength mylength;
	mylength.setRaw(10000000000000000);
	double lenm = mylength.in_m();
	std::cout << "length in m: " << lenm;

	QLength myotherlength;
	myotherlength = 10.56_nm;

	return 5;
}