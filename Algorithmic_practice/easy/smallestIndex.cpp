#include <algorithm>
#include <climits>
#include <vector>

class Solution {
private:
  int _sum_num(int num) {
    int res = 0;
    while (num > 0) {
      res += num % 10;
      num /= 10;
    }
    return res;
  }

public:
  int smallestIndex(const std::vector<int> &nums) {
    int ans = INT_MAX;
    for (int idx = 0; idx < nums.size(); ++idx) {
      int res = _sum_num(nums[idx]);
      if (res == idx) {
        ans = std::min(ans, idx);
      }
    }
    return (ans != INT_MAX) ? ans : -1;
  }
};
