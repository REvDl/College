#include <string>

class Solution {
public:
  std::string removeOuterParentheses(std::string s) {
    std::string res;
    int count = 0;
    for (char char_s : s) {
      if (char_s == '(') {
        if (count > 0) {
          res.push_back(char_s);
        }
        count++;
      } else {
        count--;
        if (count > 0) {
          res.push_back(char_s);
        }
      }
    }
    return res;
  }
};
