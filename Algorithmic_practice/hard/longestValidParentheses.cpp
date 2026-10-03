#include <algorithm>
#include <string>

class Solution {
public:
  int longestValidParentheses(std::string s) {
    int max_len = 0;
    int left_cnt = 0, right_cnt = 0;

    for (char c : s) {
      if (c == '(')
        left_cnt++;
      else if (c == ')')
        right_cnt++;

      if (right_cnt > left_cnt) {
        left_cnt = 0;
        right_cnt = 0;
      }
      if (left_cnt == right_cnt) {
        max_len = std::max(max_len, left_cnt * 2);
      }
    }

    left_cnt = 0;
    right_cnt = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '(')
        left_cnt++;
      else if (s[i] == ')')
        right_cnt++;

      if (left_cnt > right_cnt) {
        left_cnt = 0;
        right_cnt = 0;
      }
      if (left_cnt == right_cnt) {
        max_len = std::max(max_len, left_cnt * 2);
      }
    }

    return max_len;
  }
};
