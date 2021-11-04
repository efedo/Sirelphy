#include "pch.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/unitlib/units.h"

TEST(TestCaseName, TestName) {
  cVector3D testVec;

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Core, Compilation) {
	units::Length mylength;
	mylength.setRaw(10000000000000000);
	double lenm = mylength.get_m();
	std::cout << "length in m: " << lenm;

	units::Length myotherlength;

	using namespace units;
	myotherlength.set_meters(10.56);
}

TEST(UnitLib, Velocity) {
	units::Time time;
	time.set_minutes(5.4);
	//time.debugUnitPrint();
	units::Distance distance;
	distance.set_km(3.4);
	//distance.debugUnitPrint();
	units::Velocity velocity = distance / time;
	EXPECT_EQ(velocity.get_meters_per_second(), 3400.0 / 324.0);
	EXPECT_EQ(float(velocity.get_km_per_h()), float(3400.0 / 1166.4));
	units::Time newtime;
	newtime.set_hours(3.4);
	//units::Distance travelled = velocity * newtime;
	EXPECT_EQ(float(velocity.get_km_per_h() * 3.4), float(11560.0 / 1166.4));
	//std::cout << blah.in_m_per_s() << "/n";
	//blah.debugUnitPrint();
}