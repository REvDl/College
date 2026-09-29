#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;
    std::unordered_map<char, char> valid = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        stack.push(ch);
      } else {
        if (stack.empty() || stack.top() != valid[ch]) {
          return false;
        }
        stack.pop();
      }
    }

    return stack.empty();
  }
};
