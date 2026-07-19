#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  std::string smallestSubsequence(std::string s) {
    std::string stack = "";
    std::unordered_map<char, int> count_char;
    std::unordered_set<char> visited;

    for (char ch : s) {
      count_char[ch]++;
    }

    for (char ch : s) {
      count_char[ch]--;

      if (visited.count(ch)) {
        continue;
      }

      while (!stack.empty() && stack.back() > ch &&
             count_char[stack.back()] > 0) {
        visited.erase(stack.back());
        stack.pop_back();
      }

      stack.push_back(ch);
      visited.insert(ch);
    }

    return stack;
  }
};
