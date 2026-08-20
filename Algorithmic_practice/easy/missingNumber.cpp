#include <numeric>
#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int n = nums.size();
    int need_sum = 0;
    for (int num = 0; num <= n; ++num) {

      need_sum += num;
    }

    int actual_sum = std::accumulate(nums.begin(), nums.end(), 0);
    return need_sum - actual_sum;
  }
};
