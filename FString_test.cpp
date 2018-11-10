#include <FString.h>
#include <gtest/gtest.h>

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using namespace sc;

TEST(empty_test, empty_test_em_Test){
  FString f1;
  EXPECT_EQ(true, f1.empty());
}

TEST(temporay_var, temporay_var_te_Test){
  FString f1;
  f1 = "i am a temporary variable";
  EXPECT_EQ(f1.rc(), 1);
}

TEST(copy_operator, copy_operator_co_Test){
  FString f1("liangshaocong");
  EXPECT_EQ(f1.rc(), 1);
  FString f2;
  f2 = f1;
  EXPECT_EQ(f1.rc(), f2.rc());
  EXPECT_EQ(f1.rc(), 2);
}

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