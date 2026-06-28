#include <vector>

using namespace std;

class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      if (num != 0) {
        int circle_idx = ((i + num) % n + n) % n;
        result[i] = nums[circle_idx];
      } else {
        result[i] = 0;
      }
    }
    return result;
  }
};
