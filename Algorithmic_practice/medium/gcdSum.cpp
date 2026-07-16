#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  long long gcdSum(std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<int> prefixGcd(n, 0);
    std::vector<int> mx(n);
    std::inclusive_scan(nums.begin(), nums.end(), mx.begin(),
                        [](int a, int b) { return std::max(a, b); });
    for (size_t i = 0; i < n; ++i) {
      prefixGcd[i] = std::gcd(mx[i], nums[i]);
    }
    std::sort(prefixGcd.begin(), prefixGcd.end());
    long long res = 0;
    int left = 0, right = n - 1;
    while (left < right) {
      res += std::gcd(prefixGcd[left], prefixGcd[right]);
      left += 1;
      right -= 1;
    }
    return res;
  }
};
