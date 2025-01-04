#include <iostream>

#include "math/bignum.h"
#include "math/fib.h"

using namespace jp::math;

int main() {
  // for (uint64_t n = 0; n < 100; ++n) {
  //   BigNum result{fib(n)};
  //   std::cout << to_string(n) << ": " << to_string(result) << "\n";
  // }

  volatile BigNum result{fib(375'000)};
  return 0;
}
