#include <vector>

class Solution {
public:
  bool checkPossibility(std::vector<int> &nums) {
    bool changed = false;
    for (size_t i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] > nums[i + 1]) {
        if (changed) {
          return false;
        }
        if (i == 0 || nums[i - 1] <= nums[i + 1]) {
          nums[i] = nums[i + 1];
        } else {
          nums[i + 1] = nums[i];
        }
        changed = true;
      }
    }
    return true;
  }
};
