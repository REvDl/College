#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  int maximumLengthSubstring(std::string s) {
    int n = s.length();
    int left = 0;
    std::unordered_map<char, int> count_char;
    int max_length = 0;

    for (int right = 0; right < n; ++right) {
      char c = s[right];
      count_char[c]++;

      while (count_char[c] > 2) {
        count_char[s[left]]--;
        left++;
      }

      max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
  }
};
