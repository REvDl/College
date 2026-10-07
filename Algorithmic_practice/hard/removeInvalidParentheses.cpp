#include <algorithm>
#include <optional>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
private:
  int max_valid_len = 0;
  std::unordered_set<std::string> valid_brackets;
  std::unordered_set<std::string> visited;

  std::optional<std::pair<int, int>> isValid(const std::string &s) {
    int count = 0;
    int count_open = 0;
    int count_close = 0;

    for (char char_s : s) {
      if (char_s == '(') {
        count++;
        count_open++;
      } else if (char_s == ')') {
        count--;
        count_close++;
      }
      if (count < 0) {
        return std::nullopt;
      }
    }

    if (count == 0) {
      return std::make_pair(count_open, count_close);
    }
    return std::nullopt;
  }

  void removeForValid(const std::string &s, int prev_len) {
    if (visited.count(s)) {
      return;
    }
    visited.insert(s);

    if (static_cast<int>(s.length()) < max_valid_len) {
      return;
    }

    auto check = isValid(s);
    int curr_len = check ? (check->first + check->second) : prev_len;

    if (check) {
      if (curr_len < prev_len) {
        return;
      } else if (curr_len > prev_len) {
        max_valid_len = std::max(max_valid_len, curr_len);
        valid_brackets.clear();
        valid_brackets.insert(s);
      } else {
        valid_brackets.insert(s);
      }
    }

    for (size_t i = 0; i < s.length(); ++i) {
      if (s[i] != '(' && s[i] != ')') {
        continue;
      }
      std::string substring = s.substr(0, i) + s.substr(i + 1);
      removeForValid(substring, max_valid_len);
    }
  }

public:
  std::vector<std::string> removeInvalidParentheses(std::string s) {
    max_valid_len = 0;
    valid_brackets.clear();
    visited.clear();

    removeForValid(s, 0);

    return std::vector<std::string>(valid_brackets.begin(),
                                    valid_brackets.end());
  }
};
