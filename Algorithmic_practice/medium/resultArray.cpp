#include <vector>

class Solution {
public:
  std::vector<long long> resultArray(const std::vector<int> &nums, int k) {
    std::vector<long long> res(k, 0LL);
    std::vector<long long> dp(k, 0LL);

    for (int num : nums) {
      std::vector<long long> next_dp(k, 0LL);
      for (int j = 0; j < k; ++j) {
        int new_rem = (1LL * j * num) % k;
        next_dp[new_rem] += dp[j];
      }
      next_dp[num % k] += 1LL;

      for (int r = 0; r < k; ++r) {
        res[r] += next_dp[r];
      }
      dp = next_dp;
    }

    return res;
  }
};
