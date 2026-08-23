#include <string>

class Solution {
public:
  bool sumGame(std::string num) {
    int n = num.length();
    int mid = n / 2;
    int sum_left = 0, quetion_left = 0;
    int sum_right = 0, quetion_right = 0;

    for (int i = 0; i < n; ++i) {
      if (i < mid) {
        if (num[i] == '?') {
          quetion_left++;
        } else {
          sum_left += num[i] - '0';
        }
      } else {
        if (num[i] == '?') {
          quetion_right++;
        } else {
          sum_right += num[i] - '0';
        }
      }
    }

    int diff_sum = sum_left - sum_right;
    int diff_quetion = quetion_left - quetion_right;

    return !(diff_quetion % 2 == 0 && diff_sum * 2 + diff_quetion * 9 == 0);
  }
};
