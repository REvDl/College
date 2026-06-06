#include <numeric>
#include <vector>

class Solution {
public:
  int pivotIndex(std::vector<int> &nums) {
    int n = nums.size();
    int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0, right_sum = 0;
    for (int i = 0; i < n; ++i) {
      if (left_sum == (total_sum - left_sum - nums[i])) {
        return i;
      }
      left_sum += nums[i];
    }
    return -1;
  }
};
