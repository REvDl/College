#include <string>
#include <vector>

class Solution {
public:
  bool checkValidString(std::string s) {
    std::vector<int> stack_open;
    std::vector<int> stack_stars;

    for (int i = 0; i < s.length(); ++i) {
      char chr = s[i];
      if (chr == '(') {
        stack_open.push_back(i);
      } else if (chr == '*') {
        stack_stars.push_back(i);
      } else if (chr == ')') {
        if (!stack_open.empty()) {
          stack_open.pop_back();
        } else if (!stack_stars.empty()) {
          stack_stars.pop_back();
        } else {
          return false;
        }
      }
    }

    while (!stack_open.empty() && !stack_stars.empty()) {
      int idx_open = stack_open.back();
      stack_open.pop_back();
      int idx_stars = stack_stars.back();
      stack_stars.pop_back();

      if (idx_stars > idx_open) {
        continue;
      } else {
        return false;
      }
    }

    return stack_open.empty();
  }
};
