#include "pch.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"

TEST(TestCaseName, TestName) {
  cVector3D testVec;

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(UnitLib, Velocity) {
	units::QTime time;
	time.set_minutes(5.4);
	//time.debugUnitPrint();
	units::QDistance distance;
	distance.set_km(3.4);
	//distance.debugUnitPrint();
	units::QVelocity velocity = distance / time;
	EXPECT_EQ(velocity.in_meters_per_second(), 3400.0 / 324.0);
	EXPECT_EQ(float(velocity.in_km_per_h()), float(3400.0 / 1166.4));
	units::QTime newtime;
	newtime.set_hours(3.4);
	//units::QDistance travelled = velocity * newtime;
	EXPECT_EQ(float(velocity.in_km_per_h() * 3.4), float(11560.0 / 1166.4));
	//std::cout << blah.in_m_per_s() << "/n";
	//blah.debugUnitPrint();
}