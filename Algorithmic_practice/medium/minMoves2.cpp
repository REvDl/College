#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

class Solution {
public:
  int minMoves2(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int mid = nums[nums.size() / 2];
    int moves = 0;
    for (int num : nums) {
      moves += std::abs(num - mid);
    }
    return moves;
  }
};
