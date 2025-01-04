#include "math/bignum.h"

#include "gtest/gtest.h"

namespace jp::math {

TEST(BigNumTest, CanInstantiate) {
  BigNum zero{};
  EXPECT_EQ(0, zero[0]);
  BigNum one{1};
  EXPECT_EQ(1, one[0]);
  BigNum fifteen{15};
  EXPECT_EQ(15, fifteen[0]);
  BigNum max{std::numeric_limits<uint64_t>::max()};
  EXPECT_EQ(std::numeric_limits<uint64_t>::max(), max[0]);
}

TEST(BigNumTest, CanAdd) {
  BigNum zero{};
  BigNum one{1};
  BigNum sum{zero + one};
  EXPECT_EQ(1, sum[0]);
}

}  // namespace jp::math
