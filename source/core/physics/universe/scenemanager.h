#include "precomp.h"
#include "3d/object3d.h"
class cSceneManager {
	// List of blops organized by min x position
private:
	void addObject(cObject & newObj) {
		myObjects.insert(&newObj);
	}

	void removeObject(cObject& newObj) {
		if (myObjects.count(&newObj)) {
			myObjects.erase(&newObj);
		}
	}

	void getNearbyObjects(cObject ** objectPtrs, uint32_t & numObjs, const double & cutoffdistance) {
		numObjs = (uint32_t)(myObjects.size());
		uint32_t i = 0;
		objectPtrs
		for (std::set<cObject*>::iterator it = myObjects.begin(); it != myObjects.end(); ++it) {
			if (i = numObjs) break; // half-assed minimal thread safety
			

		}
	}

//	cWorldBin& getBin(const cVec3D_big&); // Gets the bin for this vector location
	std::set<cObject*> myObjects;
//	std::set<cWorldBin> myBins;
};