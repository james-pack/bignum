#include "math/fib.h"

#include "gtest/gtest.h"

namespace jp::math {

TEST(FibTest, MatchesSequence) {
  // From the Online Encyclopedia of Integer Sequences: https://oeis.org/A000045/list
  EXPECT_EQ(0, fib(0)[0]);
  EXPECT_EQ(1, fib(1)[0]);
  EXPECT_EQ(1, fib(2)[0]);
  EXPECT_EQ(2, fib(3)[0]);
  EXPECT_EQ(3, fib(4)[0]);
  EXPECT_EQ(5, fib(5)[0]);
  EXPECT_EQ(8, fib(6)[0]);
  EXPECT_EQ(13, fib(7)[0]);
  EXPECT_EQ(21, fib(8)[0]);
  EXPECT_EQ(34, fib(9)[0]);
  EXPECT_EQ(55, fib(10)[0]);
  EXPECT_EQ(89, fib(11)[0]);
  EXPECT_EQ(144, fib(12)[0]);
  EXPECT_EQ(233, fib(13)[0]);
  EXPECT_EQ(377, fib(14)[0]);
  EXPECT_EQ(610, fib(15)[0]);
  EXPECT_EQ(987, fib(16)[0]);
  EXPECT_EQ(1597, fib(17)[0]);
  EXPECT_EQ(2584, fib(18)[0]);
  EXPECT_EQ(4181, fib(19)[0]);
  EXPECT_EQ(6765, fib(20)[0]);
  EXPECT_EQ(10946, fib(21)[0]);
  EXPECT_EQ(17711, fib(22)[0]);
  EXPECT_EQ(28657, fib(23)[0]);
  EXPECT_EQ(46368, fib(24)[0]);
  EXPECT_EQ(75025, fib(25)[0]);
  EXPECT_EQ(121393, fib(26)[0]);
  EXPECT_EQ(196418, fib(27)[0]);
  EXPECT_EQ(317811, fib(28)[0]);
  EXPECT_EQ(514229, fib(29)[0]);
  EXPECT_EQ(832040, fib(30)[0]);
  EXPECT_EQ(1346269, fib(31)[0]);
  EXPECT_EQ(2178309, fib(32)[0]);
  EXPECT_EQ(3524578, fib(33)[0]);
  EXPECT_EQ(5702887, fib(34)[0]);
  EXPECT_EQ(9227465, fib(35)[0]);
  EXPECT_EQ(14930352, fib(36)[0]);
  EXPECT_EQ(24157817, fib(37)[0]);
  EXPECT_EQ(39088169, fib(38)[0]);
  EXPECT_EQ(63245986, fib(39)[0]);
  EXPECT_EQ(102334155, fib(40)[0]);
}

}  // namespace jp::math
