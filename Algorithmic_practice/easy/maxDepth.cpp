#include <algorithm>
#include <string>

class Solution {
public:
  int maxDepth(std::string s) {
    int max_res = 0;
    int curr_res = 0;

    for (char c : s) {
      if (c == '(') {
        curr_res++;
      } else if (c == ')') {
        curr_res--;
      }
      max_res = std::max(max_res, curr_res);
    }

    return max_res;
  }
};
