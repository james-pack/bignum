#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace jp::math {

class BigNum final {
 public:
  using StoreT = uint_fast64_t;

 private:
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

  BigNum(unsigned long v) : value_(1, v) {}

  const StoreT& operator[](size_t index) const { return value_.at(value_.size() - index - 1); }
  StoreT& operator[](size_t index) { return value_.at(value_.size() - index - 1); }

  size_t size() const { return value_.size(); }

  BigNum operator+(const BigNum& rhs) const {
    BigNum result{rhs};
    result.upsize(size());

    StoreT carry{0};
    for (size_t i = 0; i < size(); ++i) {
      carry = __builtin_add_overflow(result.value_[i], carry, &result.value_[i]);
      carry += __builtin_add_overflow(result.value_[i], value_[i], &result.value_[i]);
    }

    if (carry > 0) {
      result.value_.push_back(carry);
    }

    return result;
  }
};

inline std::string to_string(const BigNum& n) {
  // TODO(james): This is a quick and dirty form of this function for debug info. Either remove or
  // fix.
  using std::to_string;
  std::string result{};
  for (size_t i = 0; i < n.size(); ++i) {
    BigNum::StoreT value{n[n.size() - i - 1]};
    result.append(to_string(value));
    result.append(" ");
  }
  return result;
}

}  // namespace jp::math
