#include "math/bignum.h"

#include "gtest/gtest.h"

namespace jp::math {

TEST(BigNumTest, CanCompile) {
  BigNum zero{};
  EXPECT_EQ(0, zero[0]);
}

}  // namespace jp::math
