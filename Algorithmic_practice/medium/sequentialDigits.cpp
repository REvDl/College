#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> sequentialDigits(int low, int high) {
    std::vector<int> res;
    for (int start = 1; start <= 9; ++start) {
      long long num = start;
      int new_num = start + 1;
      while (num <= high && new_num <= 9) {
        num = num * 10 + new_num;
        if (num >= low && num <= high) {
          res.push_back(num);
        }
        new_num++;
      }
    }
    std::sort(res.begin(), res.end());
    return res;
  }
};
