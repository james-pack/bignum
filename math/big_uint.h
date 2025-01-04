#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace jp::math {

class BigUint final {
 public:
  using StoreT = uint_fast64_t;

 private:
  std::vector<StoreT> value_{0};

  void upsize(size_t size, size_t capacity) {
    value_.reserve(capacity);
    if (value_.size() < size) {
      value_.resize(size);
    }
  }

  friend BigUint operator+(const BigUint& lhs, const BigUint& rhs);
  friend BigUint operator+(BigUint&& lhs, const BigUint& rhs);

 public:
  BigUint() = default;

  BigUint(const BigUint&) = default;

  BigUint(BigUint&&) = default;
  BigUint& operator=(const BigUint&) = default;
  BigUint& operator=(BigUint&&) = default;

  BigUint(unsigned long v) : value_(1, v) {}

  const StoreT& operator[](size_t index) const { return value_.at(value_.size() - index - 1); }
  StoreT& operator[](size_t index) { return value_.at(value_.size() - index - 1); }

  size_t size() const { return value_.size(); }
};

inline BigUint operator+(const BigUint& lhs, const BigUint& rhs) {
  BigUint result{};

  result.upsize(std::max(lhs.value_.size(), rhs.value_.size()),
                std::max(lhs.value_.capacity(), rhs.value_.capacity()));

  BigUint::StoreT carry{0};
  for (size_t i = 0; i < rhs.size(); ++i) {
    carry = __builtin_add_overflow(lhs.value_[i], carry, &result.value_[i]);
    carry += __builtin_add_overflow(result.value_[i], rhs.value_[i], &result.value_[i]);
  }

  if (carry > 0) {
    result.value_.push_back(carry);
  }

  return result;
}

inline BigUint operator+(BigUint&& lhs, const BigUint& rhs) {
  BigUint result{std::move(lhs)};

  result.upsize(rhs.value_.size(), rhs.value_.capacity());

  BigUint::StoreT carry{0};
  for (size_t i = 0; i < rhs.size(); ++i) {
    carry = __builtin_add_overflow(result.value_[i], carry, &result.value_[i]);
    carry += __builtin_add_overflow(result.value_[i], rhs.value_[i], &result.value_[i]);
  }

  if (carry > 0) {
    result.value_.push_back(carry);
  }

  return result;
}

inline std::string to_string(const BigUint& n) {
  // TODO(james): This is a quick and dirty form of this function for debug info. Either remove or
  // fix.
  using std::to_string;
  std::string result{};
  for (size_t i = 0; i < n.size(); ++i) {
    BigUint::StoreT value{n[i]};
    result.append(to_string(value));
    result.append(" ");
  }
  return result;
}

}  // namespace jp::math
