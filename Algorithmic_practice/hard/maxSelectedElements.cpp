#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSelectedElements(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> max_consecutives;

    for (int num : nums) {
      int next_x = max_consecutives[num];
      int prev_x = max_consecutives[num - 1];
      max_consecutives[num] = max(prev_x + 1, next_x);
      max_consecutives[num + 1] = next_x + 1;
    }

    int ans = 0;
    for (const auto &[key, val] : max_consecutives) {
      ans = max(ans, val);
    }

    return ans;
  }
};
