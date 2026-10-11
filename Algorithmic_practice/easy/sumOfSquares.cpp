#include <vector>

class Solution {
public:
  int sumOfSquares(std::vector<int> &nums) {
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (n % (i + 1) == 0) {
        res += pow(nums[i], 2);
      }
    }
    return res;
  }
};
