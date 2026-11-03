#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  int minMoves(std::vector<int> &nums) {
    int max_num = *std::max_element(nums.begin(), nums.end());
    int sum = 0;
    for (int num : nums) {
      sum += max_num - num;
    }
    return sum;
  }
};
