#include <iostream>

#include "math/big_uint.h"
#include "math/fib.h"

using namespace jp::math;

int main() {
  // for (uint64_t n = 0; n < 100; ++n) {
  //   BigUint result{fib(n)};
  //   std::cout << n << ": " << to_string(result) << "\n";
  // }

  BigUint result{fib(500'000)};
  // BigUint result{fib(1'000'000)};
  // std::cout << to_string(result) << "\n";
  // std::cout << "result.size(): " << result.size() << "\n";
  return 0;
}
