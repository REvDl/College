#include <vector>

class Solution {
public:
  int sortPermutation(const std::vector<int> &nums) {
    std::vector<int> indexes;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i) {
        indexes.push_back(nums[i]);
      }
    }
    int res = indexes.empty() ? 0 : indexes[0];
    for (size_t i = 1; i < indexes.size(); ++i) {
      res &= indexes[i];
    }
    return res;
  }
};
