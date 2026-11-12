#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int longestMonotonicSubarray(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int left_inc = 0;
    int left_dec = 0;
    int max_inc = 1;
    int max_dec = 1;
    for (int right = 1; right < nums.size(); ++right) {
      if (nums[right - 1] >= nums[right]) {
        left_inc = right;
      }
      max_inc = max(max_inc, right - left_inc + 1);
      if (nums[right - 1] <= nums[right]) {
        left_dec = right;
      }
      max_dec = max(max_dec, right - left_dec + 1);
    }
    return max(max_inc, max_dec);
  }
};
