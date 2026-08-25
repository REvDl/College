#include <unordered_set>
#include <vector>

class Solution {
public:
  int missingMultiple(std::vector<int> &nums, int k) {
    int multiple = k;
    std::unordered_set<int> nums_set(nums.begin(), nums.end());
    while (true) {
      if (nums_set.find(multiple) == nums_set.end()) {
        return multiple;
      }
      multiple += k;
    }
  }
};
