#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  int findGCD(std::vector<int> &nums) {
    int max_val = *std::max_element(nums.begin(), nums.end());
    int min_val = *std::min_element(nums.begin(), nums.end());
    return std::gcd(max_val, min_val);
  }
};
