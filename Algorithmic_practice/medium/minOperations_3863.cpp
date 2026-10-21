#include <algorithm>
#include <string>

class Solution {
public:
  int minOperations(std::string s) {
    std::string sort_s = s;
    std::sort(sort_s.begin(), sort_s.end());

    int n = s.length();

    if (s == sort_s) {
      return 0;
    }
    if (n <= 2) {
      return -1;
    }
    if (s[0] == sort_s[0] || s[n - 1] == sort_s[n - 1]) {
      return 1;
    }

    std::string sub = s.substr(1, n - 2);

    if (s[0] == sort_s[n - 1] && s[n - 1] == sort_s[0] &&
        sub.find(sort_s[0]) == std::string::npos &&
        sub.find(sort_s[n - 1]) == std::string::npos) {
      return 3;
    }

    return 2;
  }
};
