#include "gtest/gtest.h"

TEST(SString, DoesConstruct) {
  ASSERT_TRUE(true);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
