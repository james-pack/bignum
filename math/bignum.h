#pragma once

#include <cstdint>
#include <vector>

namespace jp::math {

class BigNum final {
 private:
  using StoreT = uint64_t;

  std::vector<StoreT> value_{};

 public:
  BigNum() = default;
  BigNum(const BigNum&) = default;
  BigNum(BigNum&&) = default;
  BigNum& operator=(const BigNum&) = default;
  BigNum& operator=(BigNum&&) = default;

  BigNum(int i) : value_(1, i) {}
  BigNum(unsigned long i) : value_(1, i) {}
};

}  // namespace jp::math
