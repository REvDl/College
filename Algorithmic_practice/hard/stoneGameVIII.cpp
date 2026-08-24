#include <algorithm>
#include <vector>

class Solution {
public:
  int stoneGameVIII(std::vector<int> &stones) {
    int n = stones.size();
    std::vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + stones[i];
    }
    int max_prefix = prefix_sum[n];
    for (int i = n - 1; i > 1; --i) {
      max_prefix = std::max(max_prefix, prefix_sum[i] - max_prefix);
    }
    return max_prefix;
  }
};
