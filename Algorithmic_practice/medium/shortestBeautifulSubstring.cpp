#include <string>

class Solution {
public:
  std::string shortestBeautifulSubstring(std::string s, int k) {
    int n = s.length();
    std::string result = "";
    int left = 0, count = 0;

    for (int right = 0; right < n; ++right) {
      if (s[right] == '1')
        count++;

      while (count == k) {
        std::string current = s.substr(left, right - left + 1);

        if (result.empty() || current.length() < result.length() ||
            (current.length() == result.length() && current < result)) {
          result = current;
        }

        if (s[left] == '1')
          count--;
        left++;
      }
    }
    return result;
  }
};
