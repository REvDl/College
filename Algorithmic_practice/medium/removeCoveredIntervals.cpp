#include <algorithm>
#include <vector>

class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
    const int n = intervals.size();
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                if (a[0] != b[0]) {
                  return a[0] < b[0];
                }
                return a[1] > b[1];
              });
    int res = n, max_r = intervals[0][1];
    for (size_t i = 1; i < n; ++i) {
      if (intervals[i][1] > max_r) {
        max_r = intervals[i][1];
      } else
        res -= 1;
    }
    return res;
  }
};
