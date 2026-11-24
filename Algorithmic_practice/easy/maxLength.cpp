#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int maxLength(vector<int> &nums) {
    int res = 1;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int p = 1, g = 0, l = 1;
      for (int j = i; j < n; ++j) {
        int x = nums[j];
        p *= x;
        g = gcd(g, x);
        l = lcm(l, x);
        if (p == g * l) {
          res = max(res, j - i + 1);
        } else if (p > g * l) {
          break;
        }
      }
    }
    return res;
  }
};
