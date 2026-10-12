#include <vector>

class Solution {
public:
  int maxSum(std::vector<int> &nums, int k) {
    int n = nums.size();
    long long MOD = 1e9 + 7;
    std::vector<int> bits(30, 0);

    for (int num : nums) {
      for (int i = 0; i < 30; ++i) {
        if ((num >> i) & 1) {
          bits[i]++;
        }
      }
    }

    long long res = 0;
    for (int j = 0; j < k; ++j) {
      long long num = 0;
      for (int i = 0; i < 30; ++i) {
        if (bits[i] > 0) {
          num += (1 << i);
          bits[i]--;
        }
      }
      res = (res + (num * num) % MOD) % MOD;
    }

    return res;
  }
};
