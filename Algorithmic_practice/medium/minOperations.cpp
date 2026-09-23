#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minOperations(std::vector<int> &nums, int x) {
    long long n = nums.size();
    long long ans = LLONG_MAX;

    std::vector<long long> prefix_sum(n + 1, 0);
    std::unordered_map<long long, long long> suffix_sum;

    for (long long i = 0; i < n; ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    long long curr_sum = 0;
    for (long long i = n - 1; i >= 0; --i) {
      curr_sum += nums[i];
      suffix_sum[curr_sum] = n - i;
    }
    suffix_sum[0] = 0;

    for (long long i = 0; i <= n; ++i) {
      long long p = prefix_sum[i];
      long long target = x - p;
      if (suffix_sum.count(target) && (i + suffix_sum[target] <= n)) {
        ans = std::min(ans, suffix_sum[target] + i);
      }
    }

    return ans != LLONG_MAX ? static_cast<int>(ans) : -1;
  }
};
