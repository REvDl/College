#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumSumSubarray(vector<int> &nums, int l, int r) {
    int min_sum = INT_MAX;
    int n = nums.size();
    vector<int> prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    }

    for (int left = 0; left < n; ++left) {
      for (int k = l; k <= r; ++k) {
        if (left + k <= n) {
          int curr_sum = prefix_sum[left + k] - prefix_sum[left];
          if (curr_sum > 0) {
            min_sum = min(min_sum, curr_sum);
          }
        }
      }
    }

    return (min_sum == INT_MAX) ? -1 : min_sum;
  }
};
