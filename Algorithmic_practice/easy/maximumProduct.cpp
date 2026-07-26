#include <algorithm>
#include <vector>

class Solution {
public:
  int maximumProduct(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    int res_one = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int res_two = nums[0] * nums[1] * nums[n - 1];

    return std::max(res_one, res_two);
  }
};
