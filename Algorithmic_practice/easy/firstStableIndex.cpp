#include <algorithm>
#include <vector>

class Solution {
public:
  int firstStableIndex(const std::vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0)
      return -1;

    std::vector<int> prefix_max(n);
    prefix_max[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      prefix_max[i] = std::max(prefix_max[i - 1], nums[i]);
    }

    std::vector<int> suffix_min(n);
    suffix_min[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      suffix_min[i] = std::min(suffix_min[i + 1], nums[i]);
    }

    for (int i = 0; i < n; ++i) {
      if (prefix_max[i] - suffix_min[i] <= k) {
        return i;
      }
    }

    return -1;
  }
};
