#include <cmath>
#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> leftRightDifference(std::vector<int> &nums) {
    int n = nums.size(), left_sum = 0;
    int array_sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::vector<int> ans;
    ans.reserve(n);
    for (const auto &num : nums) {
      int right_sum = array_sum - left_sum - num;
      ans.push_back(std::abs(right_sum - left_sum));
      left_sum += num;
    }
    return ans;
  }
};
