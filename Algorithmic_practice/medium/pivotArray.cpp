#include <vector>

class Solution {
public:
  std::vector<int> pivotArray(std::vector<int> &nums, int pivot) {
    std::vector<int> pivot_big, pivot_small, pivot_mid;
    pivot_small.reserve(nums.size());
    for (int num : nums) {
      if (num < pivot)
        pivot_small.push_back(num);
      else if (num > pivot)
        pivot_big.push_back(num);
      else
        pivot_mid.push_back(num);
    }
    pivot_small.insert(pivot_small.end(), pivot_mid.begin(), pivot_mid.end());
    pivot_small.insert(pivot_small.end(), pivot_big.begin(), pivot_big.end());
    return pivot_small;
  }
};
