#include <FString.h>
#include <gtest/gtest.h>

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using namespace sc;

TEST(equal_test, fstring_eq_Test){
  FString f1("liangshaocong");
  FString f2(f1);

  EXPECT_EQ(true, f1 == f1);
  EXPECT_EQ(true, f1 == f2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}