#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int minSumOfLengths(std::vector<int> &arr, int target) {
    int n = arr.size();
    std::vector<int> dp(n + 1, INT_MAX);

    int curr_sum = 0;
    int left = 0;
    int ans = INT_MAX;

    for (int right = 0; right < n; ++right) {
      curr_sum += arr[right];

      while (curr_sum > target && left <= right) {
        curr_sum -= arr[left];
        left++;
      }

      dp[right + 1] = dp[right];

      if (curr_sum == target) {
        int current_len = right - left + 1;

        if (dp[left] != INT_MAX) {
          ans = std::min(ans, current_len + dp[left]);
        }

        dp[right + 1] = std::min(current_len, dp[right]);
      }
    }

    return (ans == INT_MAX) ? -1 : ans;
  }
};
