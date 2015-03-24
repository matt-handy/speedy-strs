#include "gtest/gtest.h"
#include "s-string.h"

using namespace speedystring;

TEST(SString, DoesEQUALITY) {
  SString control("Control");
  SString notControl("Not control");
  SString otherControl("Control");
  ASSERT_TRUE(control.equals(otherControl));
  ASSERT_FALSE(control.equals(notControl));
}

TEST(SString, DoesCONTAINS){
  SString control("Control");
  SString notControl("Not control");
  SString otherControl("control");
  SString defNotControl("definitely not");

  ASSERT_FALSE(control.contains(notControl));
  ASSERT_TRUE(notControl.contains(otherControl));
  ASSERT_FALSE(defNotControl.contains(otherControl));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
