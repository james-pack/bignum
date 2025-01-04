#include "math/bignum.h"

namespace jp::math {

BigNum fib(unsigned long n) {
  BigNum a{0UL};
  BigNum b{1UL};

  while (n-- > 0) {
    BigNum temp{std::move(a)};
    a = std::move(b);
    b = temp + a;
  }

  return a;
}

}  // namespace jp::math
