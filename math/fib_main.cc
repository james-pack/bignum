#include <iostream>

#include "math/bignum.h"
#include "math/fib.h"

using namespace jp::math;

int main() {
  // for (uint64_t n = 0; n < 100; ++n) {
  //   BigNum result{fib(n)};
  //   std::cout << n << ": " << to_string(result) << "\n";
  // }

  BigNum result{fib(440'000)};
  // BigNum result{fib(1'000'000)};
  // std::cout << to_string(result) << "\n";
  // std::cout << "result.size(): " << result.size() << "\n";
  return 0;
}
