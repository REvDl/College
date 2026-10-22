#include <algorithm>
#include <vector>

class Solution {
private:
  bool canSorting(const std::vector<int> &nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        count++;
      }
    }
    if (nums[n - 1] > nums[0]) {
      count++;
    }
    return count <= 1;
  }

public:
  int minOperations(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> rev_nums = nums;
    std::reverse(rev_nums.begin(), rev_nums.end());

    if (!canSorting(nums) && !canSorting(rev_nums)) {
      return -1;
    }

    std::vector<int> res;
    auto it = std::find(nums.begin(), nums.end(), 0);
    int idx = std::distance(nums.begin(), it);

    if (canSorting(nums)) {
      res.push_back(idx);
      res.push_back(n - idx + 2);
    }
    if (canSorting(rev_nums)) {
      res.push_back(n - idx);
      res.push_back(idx + 2);
    }

    return *std::min_element(res.begin(), res.end());
  }
};
