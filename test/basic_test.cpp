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

TEST(SString, DoesEMPTY){
  SString empty("");
  SString notEmpty("not");

  ASSERT_TRUE(empty.empty());
  ASSERT_FALSE(notEmpty.empty());
}

TEST(SString, DoesSPLIT){
  SString base("This is my super awesome base string");
  SString nullDelim("NULL");
  SString white(" ");
  SString eWhite("e ");

  std::vector<SString> nullV = base.split(nullDelim);
  ASSERT_TRUE(nullV.size() == 1);
  ASSERT_TRUE(nullV.at(0).equals(SString("This is my super awesome base string")));

  std::vector<SString> whiteV = base.split(white);
  ASSERT_TRUE(whiteV.size() == 7);
  ASSERT_TRUE(whiteV.at(0).equals(SString("This")));  
  ASSERT_TRUE(whiteV.at(1).equals(SString("is")));
  ASSERT_TRUE(whiteV.at(2).equals(SString("my")));
  ASSERT_TRUE(whiteV.at(3).equals(SString("super")));
  ASSERT_TRUE(whiteV.at(4).equals(SString("awesome")));
  ASSERT_TRUE(whiteV.at(5).equals(SString("base")));
  ASSERT_TRUE(whiteV.at(6).equals(SString("string")));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
