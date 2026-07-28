#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  std::string smallestPalindrome(std::string s) {
    std::vector<int> count_chars(26, 0);
    for (char c : s) {
      count_chars[c - 'a']++;
    }

    std::string left = "";
    std::string center = "";
    for (int i = 0; i < 26; ++i) {
      char ch = 'a' + i;
      left.append(count_chars[i] / 2, ch);
      if (count_chars[i] % 2 == 1 && center.empty()) {
        center = ch;
      }
    }
    std::string right = left;
    std::reverse(right.begin(), right.end());
    return left + center + right;
  }
};
