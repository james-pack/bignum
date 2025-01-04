#include "math/big_uint.h"

#include <limits>

#include "gtest/gtest.h"

namespace jp::math {

TEST(BigUintTest, CanInstantiate) {
  BigUint zero{};
  EXPECT_EQ(1, zero.size());
  EXPECT_EQ(0, zero[0]);
  BigUint one{1};
  EXPECT_EQ(1, one.size());
  EXPECT_EQ(1, one[0]);
  BigUint fifteen{15};
  EXPECT_EQ(1, fifteen.size());
  EXPECT_EQ(15, fifteen[0]);
  BigUint max{std::numeric_limits<uint64_t>::max()};
  EXPECT_EQ(1, max.size());
  EXPECT_EQ(std::numeric_limits<uint64_t>::max(), max[0]);
}

TEST(BigUintTest, CanAdd) {
  BigUint zero{};
  BigUint one{1};
  BigUint sum{zero + one};
  ASSERT_EQ(1, sum.size());
  EXPECT_EQ(1, sum[0]);
}

TEST(BigUintTest, CanAddWithCarry) {
  BigUint max{std::numeric_limits<uint64_t>::max()};
  BigUint one{1};
  BigUint sum{max + one};
  ASSERT_EQ(2, sum.size());
  EXPECT_EQ(0, sum[1]);
  EXPECT_EQ(1, sum[0]);
}

}  // namespace jp::math
