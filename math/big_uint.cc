#include "math/big_uint.h"

#include <cstdint>
#include <string>
#include <vector>

namespace jp::math {

std::string to_string(const BigUint& n) {
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
