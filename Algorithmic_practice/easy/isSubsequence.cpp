#include <string>

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    int res = 0;
    int i = 0;
    int j = 0;
    int len_s = s.length();
    int len_t = t.length();

    while (i < len_s && j < len_t) {
      if (s[i] == t[j]) {
        res += 1;
        i += 1;
      }
      j += 1;
    }

    return res == len_s;
  }
};
