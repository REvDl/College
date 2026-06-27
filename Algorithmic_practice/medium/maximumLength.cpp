#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumLength(vector<int> &nums) {
    unordered_map<long long, int> frequency;
    for (int x : nums) {
      frequency[x]++;
    }
    int max_subset = 0;
    if (frequency.count(1)) {
      int count_one = frequency[1];
      max_subset = (count_one % 2 != 0) ? count_one : count_one - 1;
    }
    for (auto const &[x, count] : frequency) {
      if (x == 1) {
        continue;
      }
      int current_subset = 0;
      long long num = x;
      while (frequency.count(num) && frequency[num] >= 2) {
        current_subset += 2;
        num = num * num;
      }

      if (frequency.count(num) && frequency[num] >= 1) {
        current_subset += 1;
      } else {
        current_subset -= 1;
      }

      max_subset = max(max_subset, current_subset);
    }
    return max_subset;
  }
};
