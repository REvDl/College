#include <string>
#include <vector>

class Solution {
public:
  int numDistinct(std::string s, std::string t) {
    int n = s.length();
    int m = t.length();
    std::vector<std::vector<unsigned long long>> dp(
        n + 1, std::vector<unsigned long long>(m + 1, 0));

    for (int i = 0; i <= n; ++i) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] += dp[i - 1][j - 1];
        }
      }
    }

    return dp[n][m];
  }
};
