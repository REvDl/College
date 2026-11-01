#include <vector>

class Solution {
public:
  int minMoves(std::vector<int> &nums) {
    long long sum = 0;
    int min_val = nums[0];

    for (int num : nums) {
      sum += num;
      if (num < min_val) {
        min_val = num;
      }
    }

    return sum - (long long)min_val * nums.size();
  }
};
