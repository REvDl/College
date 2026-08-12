#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxSubarrayLength(std::vector<int> &nums, int k) {
    int n = nums.size();
    int left = 0;
    std::unordered_map<int, int> count_nums;
    int max_len = 0;

    for (int right = 0; right < n; ++right) {
      count_nums[nums[right]]++;
      while (count_nums[nums[right]] > k) {
        count_nums[nums[left]]--;
        left++;
      }
      max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
  }
};
