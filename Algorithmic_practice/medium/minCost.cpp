#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int minCost(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<std::unordered_set<int>>> dp(
        m, std::vector<std::unordered_set<int>>(n));

    dp[0][0].insert(grid[0][0]);

    for (int j = 1; j < n; ++j) {
      for (int val : dp[0][j - 1]) {
        dp[0][j].insert(val ^ grid[0][j]);
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int val : dp[i - 1][0]) {
        dp[i][0].insert(val ^ grid[i][0]);
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        for (int prev_xor : dp[i - 1][j]) {
          dp[i][j].insert(prev_xor ^ grid[i][j]);
        }
        for (int prev_xor : dp[i][j - 1]) {
          dp[i][j].insert(prev_xor ^ grid[i][j]);
        }
      }
    }

    return *std::min_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
  }
};
