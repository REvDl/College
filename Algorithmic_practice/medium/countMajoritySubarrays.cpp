#include <vector>

using namespace std;

class Solution {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    const int n = nums.size();
    vector<int> prefix_sum(n + 1, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int val_num;
      if (nums[i] != target)
        val_num = -1;
      else
        val_num = 1;
      prefix_sum[i + 1] = prefix_sum[i] + val_num;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        int sum_p = prefix_sum[j + 1] - prefix_sum[i];
        if (sum_p > 0) {
          res += 1;
        }
      }
    }
    return res;
  }
};
