#include "math/fib.h"

#include "math/big_uint.h"

namespace jp::math {

BigUint fib(unsigned long n) {
  BigUint a{0UL};
  BigUint b{1UL};

  while (n-- > 0) {
    BigUint temp{std::move(a)};
    a = std::move(b);
    b = std::move(temp) + a;
  }

  return a;
}

}  // namespace jp::math
