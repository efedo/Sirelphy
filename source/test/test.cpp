#include "pch.h"
#include "Sirelphy/source/core/physics/vector/vector.h"
#include "Sirelphy/source/core/unitlib/unitlib.h"

TEST(TestCaseName, TestName) {
  cVector3D testVec;

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

  unittime::QTime time;
  time.set_minutes(5.4);
  time.debugUnitPrint();
  length::QDistance distance;
  distance.set_km(3.4);
  distance.debugUnitPrint();
  auto blah = distance / time;
  std::cout << blah.in_m_per_s() << "/n";
  blah.debugUnitPrint();
}