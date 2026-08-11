#include <unordered_set>
#include <vector>

class Solution {
public:
  int missingInteger(std::vector<int> &nums) {
    int n = nums.size();
    int max_prefix_sum = nums[0];

    for (int i = 1; i < n; ++i) {
      if (nums[i] == nums[i - 1] + 1) {
        max_prefix_sum += nums[i];
      } else {
        break;
      }
    }

    std::unordered_set<int> nums_set(nums.begin(), nums.end());
    while (nums_set.count(max_prefix_sum)) {
      max_prefix_sum += 1;
    }

    return max_prefix_sum;
  }
};
