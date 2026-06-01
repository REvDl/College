#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int arrayPairSum(vector<int> &nums) {
    int total_sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      total_sum += nums[i];
    }
    return total_sum;
  }
};
