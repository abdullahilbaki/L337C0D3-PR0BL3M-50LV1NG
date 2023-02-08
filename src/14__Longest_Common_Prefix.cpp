#include <catch2/catch_test_macros.hpp>

//
//
//
//

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  [[nodiscard]] std::string
  longestCommonPrefix(std::vector<std::string> &strs) const noexcept {

    if (strs.empty())
      return {};

    std::sort(strs.begin(), strs.end());

    auto pair = std::mismatch(strs.front().begin(), strs.front().end(),
                              strs.back().begin(), strs.back().end());

    return std::string{strs.front().substr(
        0, static_cast<long unsigned int>(pair.first - strs.front().begin()))};
  }
};

//
//
//
//

TEST_CASE() {

  Solution s;

  std::vector<std::string> input{"flower", "flow", "flight"};
  REQUIRE(s.longestCommonPrefix(input) == "fl");

  input = {"dog", "racecar", "car"};
  REQUIRE(s.longestCommonPrefix(input) == "");
}
