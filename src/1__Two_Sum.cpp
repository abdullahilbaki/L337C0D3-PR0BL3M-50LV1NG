#include <catch2/catch_test_macros.hpp>

//
//
//
//

#include <cstddef>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {

    std::unordered_map<int, int> map{};
    std::vector<int> result{};

    for (std::size_t i{}; i < nums.size(); i++) {

      const auto it = map.find(target - nums[i]);
      if (it != map.end()) {
        result.push_back(it->second);
        result.push_back(static_cast<int>(i));
        break;
      }

      map.emplace(nums[i], static_cast<int>(i));
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

  std::vector<int> input{2, 7, 11, 15};
  std::vector<int> output{0, 1};
  REQUIRE(s.twoSum(input, 9) == output);

  input = {3, 2, 4};
  output = {1, 2};
  REQUIRE(s.twoSum(input, 6) == output);

  input = {3, 3};
  output = {0, 1};
  REQUIRE(s.twoSum(input, 6) == output);
}
