#pragma once

#include <cstdint>
#include <vector>

namespace jp::math {

class BigNum final {
 private:
  using StoreT = uint64_t;

  std::vector<StoreT> value_{1, 0};

  void upsize(size_t s) {
    if (value_.size() < s) {
      value_.resize(s);
    }
  }

 public:
  BigNum() = default;
  BigNum(const BigNum&) = default;
  BigNum(BigNum&&) = default;
  BigNum& operator=(const BigNum&) = default;
  BigNum& operator=(BigNum&&) = default;

  BigNum(int i) : value_(1, i) {}
  BigNum(unsigned long i) : value_(1, i) {}

  BigNum operator+(const BigNum& rhs) const {
    BigNum result{rhs};
    result.upsize(value_.size());

    StoreT carry{0};
    for (size_t i = 0; i < value_.size(); ++i) {
      result.value_[i] += value_[i] + carry;
      if (result.value_[i] < value_[i]) {
        carry = 1;
      }
    }

    if (carry > 0) {
      result.upsize(result.value_.size() + 1);
      result.value_[result.value_.size() - 1] = 1;
    }

    return result;
  }

  const StoreT& operator[](size_t i) const { return value_.at(value_.size() - i - 1); }
};

}  // namespace jp::math
