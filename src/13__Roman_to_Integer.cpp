#include <catch2/catch_test_macros.hpp>

//
//
//
//

#include <cstddef>
#include <string>
#include <unordered_map>

class Solution {
public:
  int romanToInt(std::string s) {

    static const std::unordered_map<char, int> romanValue{
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

    auto result{0};

    for (std::size_t i{}; i < s.size(); i++) {

      auto current = romanValue.at(s[i]);
      auto next = (i + 1 < s.size()) ? romanValue.at(s[i + 1]) : 0;

      if (current < next)
        result -= current;
      else
        result += current;
    }

    return result;
  }
};

//
//
//
//

TEST_CASE() {
  Solution s;

  REQUIRE(s.romanToInt("III") == 3);
  REQUIRE(s.romanToInt("LVIII") == 58);
  REQUIRE(s.romanToInt("MCMXCIV") == 1994);
}
