#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int climbStairs(int n, std::vector<int> &costs) {
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int step = 0; step < 4; ++step) {
        if (i - step >= 0) {
          int prev_step = i - step;
          if (dp[prev_step] != INT_MAX) {
            int jump_cost = costs[i - 1] + (step * step);
            dp[i] = std::min(dp[i], dp[prev_step] + jump_cost);
          }
        }
      }
    }

    return dp[n];
  }
};
