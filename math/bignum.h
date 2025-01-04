#pragma once

#include <cstdint>
#include <string>
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

  BigNum(uint64_t v) : value_(1, v) {}

  const StoreT& operator[](size_t index) const { return value_.at(value_.size() - index - 1); }
  StoreT& operator[](size_t index) { return value_.at(value_.size() - index - 1); }

  size_t size() const { return value_.size(); }

  BigNum operator+(const BigNum& rhs) const {
    BigNum result{rhs};
    result.upsize(size());

    StoreT carry{0};
    for (size_t i = 0; i < size(); ++i) {
      carry = __builtin_add_overflow(result[i], carry, &result[i]);
      carry += __builtin_add_overflow(result[i], value_[i], &result[i]);
    }

    if (carry > 0) {
      result.upsize(result.size() + 1);
      result[result.size() - 1] = 1;
    }

    return result;
  }
};

std::string to_string(const BigNum& n) {
  // TODO(james): This is a quick and dirty form of this function for debug info. Either remove or
  // fix.
  using std::to_string;
  std::string result{};
  for (size_t i = 0; i < n.size(); ++i) {
    result.append(to_string(n[n.size() - i - 1]));
    result.append(" ");
  }
  return result;
}

}  // namespace jp::math
