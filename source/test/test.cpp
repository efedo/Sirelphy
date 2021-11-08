#include "pch.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/unitlib/units.h"

//using namespace units;

TEST(TestCaseName, TestName) {
  cVector3D testVec;

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Core, Compilation) {
	units::Length mylength;
	mylength.set_meters(10000000000000000);
	double lenm = mylength.get_meters();
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
	distance.set_kilometers(3.4);
	//distance.debugUnitPrint();
	units::Velocity velocity = distance / time;
	EXPECT_EQ(velocity.get_meters_per_second(), 3400.0 / 324.0);
	EXPECT_EQ(float(velocity.get_kilometers_per_hour()), float(3400.0 / 1166.4));
	units::Time newtime;
	newtime.set_hours(3.4);
	//units::Distance travelled = velocity * newtime;
	EXPECT_EQ(float(velocity.get_kilometers_per_hour() * 3.4), float(11560.0 / 1166.4));
	//std::cout << blah.in_m_per_s() << "/n";
	//blah.debugUnitPrint();
}

TEST(UnitLib, Energy) {
	using namespace units;
	units::Energy energy1 = 5.0_joules;
	units::Energy energy2;
	energy2.set_millijoules(500.0);
	auto energy_sum = energy1 + energy2;
	EXPECT_EQ(float(energy_sum.get_joules()), 5.5);
}

TEST(UnitLib, Frequency) {
	using namespace units;
	units::Frequency freq = 500.0_megahertz;
	units::Cycle cycles = freq * 650_seconds;
	EXPECT_EQ(float(cycles.get_cycles()), 325000000000);
}