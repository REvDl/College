#include <algorithm>
#include <vector>

class Solution {
public:
  bool predictTheWinner(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = nums[i];
    }
    for (int k = 1; k < n; ++k) {
      for (int i = 0; i < n - k; ++i) {
        int j = i + k;
        dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    return dp[0][n - 1] >= 0;
  }
};
