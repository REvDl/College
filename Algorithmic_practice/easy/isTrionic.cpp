#include <vector>

class Solution {
public:
  bool isTrionic(std::vector<int> &nums) {
    int n = nums.size();
    for (int p = 1; p < n - 2; ++p) {
      for (int q = p + 1; q < n - 1; ++q) {
        bool grow = true;
        for (int i = 1; i <= p; ++i) {
          if (nums[i] <= nums[i - 1]) {
            grow = false;
            break;
          }
        }
        bool fall = true;
        for (int i = p + 1; i <= q; ++i) {
          if (nums[i] >= nums[i - 1]) {
            fall = false;
            break;
          }
        }
        bool grow_2 = true;
        for (int i = q + 1; i < n; ++i) {
          if (nums[i] <= nums[i - 1]) {
            grow_2 = false;
            break;
          }
        }

        if (grow && fall && grow_2) {
          return true;
        }
      }
    }
    return false;
  }
};
