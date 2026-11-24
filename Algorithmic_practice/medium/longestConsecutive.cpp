#include <algorithm>
#include <climits>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set_nums(nums.begin(), nums.end());
    long long max_consecutive = LLONG_MIN;

    for (int num : set_nums) {
      long long curr_consecutive = 0;
      if (set_nums.find(num - 1) == set_nums.end()) {
        long long curr_num = num;
        while (set_nums.find(curr_num + 1) != set_nums.end()) {
          curr_consecutive++;
          curr_num++;
        }
        max_consecutive = max(max_consecutive, curr_consecutive);
      }
    }

    return max(max_consecutive + 1, 0LL);
  }
};
