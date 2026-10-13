#include <algorithm>
#include <vector>

class Solution {
public:
  long long maxAlternatingSum(std::vector<int> &nums) {
    std::vector<long long> squared(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      squared[i] = static_cast<long long>(nums[i]) * nums[i];
    }
    std::sort(squared.begin(), squared.end());

    int n = squared.size();
    int left = 0;
    int right = n - 1;
    bool plus = true;
    long long res = 0;

    while (left <= right) {
      if (plus) {
        res += squared[right];
        right--;
      } else {
        res -= squared[left];
        left++;
      }
      plus = !plus;
    }

    return res;
  }
};
