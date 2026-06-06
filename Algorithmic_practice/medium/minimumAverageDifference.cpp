#include <climits>
#include <cmath>
#include <numeric>
#include <vector>

class Solution {
public:
  int minimumAverageDifference(std::vector<int> &nums) {
    long long total_sum = std::accumulate(nums.begin(), nums.end(), 0LL),
              left_sum = 0;
    int min_diff = INT_MAX, best_index = -1, n = nums.size();
    for (int i = 0; i < n; ++i) {
      left_sum += nums[i];
      long long right_sum = total_sum - left_sum;
      int left_avg = (left_sum / (i + 1));
      int right_avg = (n - i - 1 > 0) ? (right_sum / (n - i - 1)) : 0;
      int current_avg = std::abs(left_avg - right_avg);
      if (current_avg > min_diff) {
        min_diff = current_avg;
        best_index = i;
      }
    }
    return best_index;
  }
};
