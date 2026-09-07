#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int distinctSubseqII(std::string s) {
    int n = s.length();
    long long MOD = 1000000007;
    std::unordered_map<char, int> visited;
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
      dp[i] = (2 * dp[i - 1]) % MOD;
      if (visited.find(s[i - 1]) != visited.end()) {
        dp[i] = (2 * dp[i - 1] - dp[visited[s[i - 1]] - 1] + MOD) % MOD;
      }
      visited[s[i - 1]] = i;
    }

    return (dp[n] - 1 + MOD) % MOD;
  }
};
