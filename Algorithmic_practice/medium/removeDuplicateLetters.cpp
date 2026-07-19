#include <string>
#include <vector>

class Solution {
public:
  std::string removeDuplicateLetters(std::string s) {
    std::string stack = "";
    std::vector<int> count_char(26, 0);
    std::vector<bool> visited(26, false);

    for (char ch : s) {
      count_char[ch - 'a']++;
    }

    for (char ch : s) {
      count_char[ch - 'a']--;

      if (visited[ch - 'a']) {
        continue;
      }

      while (!stack.empty() && stack.back() > ch &&
             count_char[stack.back() - 'a'] > 0) {
        visited[stack.back() - 'a'] = false;
        stack.pop_back();
      }

      stack.push_back(ch);
      visited[ch - 'a'] = true;
    }

    return stack;
  }
};
