#include <numeric>
#include <vector>

class Solution {
public:
  int waysToSplitArray(std::vector<int> &nums) {
    int n = nums.size();
    long long valid_splits = 0, left_sum = 0;
    long long total_sum = std::accumulate(nums.begin(), nums.end(), 0LL);
    for (int i = 0; i < n - 1; ++i) {
      left_sum += nums[i];
      total_sum -= nums[i];
      if (left_sum >= total_sum) {
        valid_splits += 1;
      }
    }
    return valid_splits;
  }
};
