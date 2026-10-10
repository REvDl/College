#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

class Solution {
public:
  long long minSumSquareDiff(std::vector<int> &nums1, std::vector<int> &nums2,
                             int k1, int k2) {
    int n = nums1.size();
    std::vector<int> diffs(n);
    int max_diff = 0;
    long long sum_diffs = 0;

    for (int i = 0; i < n; ++i) {
      diffs[i] = std::abs(nums1[i] - nums2[i]);
      sum_diffs += diffs[i];
      max_diff = std::max(max_diff, diffs[i]);
    }

    long long k = (long long)k1 + k2;
    if (sum_diffs <= k) {
      return 0;
    }

    std::vector<long long> counts(max_diff + 1, 0);
    for (int d : diffs) {
      counts[d]++;
    }

    for (int num = max_diff; num > 0; --num) {
      if (counts[num] == 0) {
        continue;
      }
      long long cnt = counts[num];
      if (k >= cnt) {
        counts[num] = 0;
        counts[num - 1] += cnt;
        k -= cnt;
      } else {
        counts[num] -= k;
        counts[num - 1] += k;
        break;
      }
    }

    long long ans = 0;
    for (long long num = 1; num <= max_diff; ++num) {
      if (counts[num] > 0) {
        ans += counts[num] * num * num;
      }
    }

    return ans;
  }
};
