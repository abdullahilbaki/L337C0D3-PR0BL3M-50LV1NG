#include <catch2/catch_test_macros.hpp>

//
//
//
//

#include <cstdint>
#include <string>

class Solution {
public:
  [[nodiscard]] bool isPalindrome(int x) const noexcept {

    int64_t reversed{0};

    if (x < 0 or (x != 0 and x % 10 == 0))
      return false;

    while (x > reversed) {
      reversed = reversed * 10 + x % 10;
      x /= 10;
    }

    return x == reversed or x == reversed / 10;
  }
};

//
//
//
//

TEST_CASE() {
  Solution s;

  REQUIRE(s.isPalindrome(121) == true);
  REQUIRE(s.isPalindrome(-121) == false);
  REQUIRE(s.isPalindrome(10) == false);
}
