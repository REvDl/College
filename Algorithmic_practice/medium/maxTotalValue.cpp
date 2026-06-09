#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxTotalValue(vector<int> &nums, int k) {
    int max_val = *max_element(nums.begin(), nums.end());
    int min_val = *min_element(nums.begin(), nums.end());
    return static_cast<long long>(max_val - min_val) * k;
  }
};
