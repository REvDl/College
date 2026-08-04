#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int> findMissingElements(const std::vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }

    std::unordered_set<int> nums_set(nums.begin(), nums.end());
    std::vector<int> res;

    auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
    int min_val = *min_it;
    int max_val = *max_it;

    for (int num = min_val; num < max_val; ++num) {
      if (nums_set.find(num) == nums_set.end()) {
        res.push_back(num);
      }
    }

    return res;
  }
};
