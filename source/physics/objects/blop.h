#pragma once
#include "3d/vec3d.h"

class cMaterial {

};


class cBlop {
public:
	virtual double getApproxVolume() const { throw; }
	virtual double getExactVolume() const { throw; }
	virtual void getBounding(cVec4D_dbl&, cVec4D_dbl&) { throw; }
};

// cOctaBlop = tetrakis hexahedron
// Named octablop because it is bounded by 8 vertices

// Maybe some good example resources:
// https://github.com/MRPT/mrpt/tree/master/libs/opengl/include/mrpt/opengl
class cOctaBlop : public cBlop {
public:
	cOctaBlop(cVec4D_dbl newvertices[8], cVec4D_big) {
		for (unsigned int i = 0; i != 8; ++i) {
			vertices[i] = newvertices[i];
		}
	}
	double volume_actual = 1.0;
	double volume_simplified = 1.0;
	bool isPlanar() const { throw; } // determines if all faces (surface quads) are planar
	bool isConvex() const { throw; } // determines if all faces (surface quads) are convex

	// Note that it does not reset bounding values first; need to supply as per desire
	void getBounding(cVec4D_dbl& low, cVec4D_dbl& high) final {
		for (uint8_t i = 0; i != 8; ++i) {
			cVec4D_dbl vert = vertices[i];
			if (vert.x < low.x) low.x = vert.x;
			if (vert.x > high.x) high.x = vert.x;
			if (vert.y < low.y) low.y = vert.y;
			if (vert.y > high.y) high.y = vert.y;
			if (vert.z < low.z) low.z = vert.z;
			if (vert.z > high.z) high.z = vert.z;
		}
	}

	// (l)eft/(r)ight, (b)ottom/(t)op, (n)ear, (f)ar
	inline cVec4D_dbl const& lbn() const { return (vertices[0]); };
	inline cVec4D_dbl const& rbn() const { return (vertices[1]); };
	inline cVec4D_dbl const& ltn() const { return (vertices[2]); };
	inline cVec4D_dbl const& rtn() const { return (vertices[3]); };
	inline cVec4D_dbl const& lbf() const { return (vertices[4]); };
	inline cVec4D_dbl const& rbf() const { return (vertices[5]); };
	inline cVec4D_dbl const& ltf() const { return (vertices[6]); };
	inline cVec4D_dbl const& rtf() const { return (vertices[7]); };

	double getApproxVolume() const final {
		cVec4D_dbl botsum = lbn() + rbn() + lbf() + rbf(); // 9 cycles
		cVec4D_dbl topsum = ltn() + rtn() + ltf() + rtf();
		cVec4D_dbl leftsum = lbn() + lbf() + ltn() + ltf();
		cVec4D_dbl rightsum = rbn() + rbf() + rtn() + rtf();
		cVec4D_dbl nearsum = lbn() + rbn() + ltn() + rtn();
		cVec4D_dbl farsum = lbf() + rbf() + ltf() + rtf(); // 54 cycles cumulative
		cVec4D_dbl bot_top = (topsum - botsum); // 3 cycles
		cVec4D_dbl left_right = (leftsum - rightsum);
		cVec4D_dbl near_far = (nearsum - farsum); // 63 cycles cumulative
		return (0.25f * lengthSpace(bot_top) * lengthSpace(left_right) * lengthSpace(near_far)); // 12 double mults, 3 double sqrts

		// Cost:
		// 63 add/sub
		// 12 mults
		// 3 sqrts

	}
private:
	cVec4D_dbl vertices[8];
	cMaterial material;
};
