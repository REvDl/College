#include <string>
#include <utility>
#include <vector>

class Solution {
public:
  std::string decodeString(std::string s) {
    std::vector<std::pair<std::string, std::string>> stack;
    std::string curr_num = "";
    std::string curr_str = "";

    for (char char_val : s) {
      if (char_val >= 'a' && char_val <= 'z') {
        curr_str += char_val;
      } else if (char_val == '[') {
        stack.push_back({curr_str, curr_num});
        curr_num = "";
        curr_str = "";
      } else if (char_val == ']') {
        auto [prev_str, prev_num] = stack.back();
        stack.pop_back();

        int repeat_count = std::stoi(prev_num);
        for (int i = 0; i < repeat_count; ++i) {
          prev_str += curr_str;
        }
        curr_str = prev_str;
      } else {
        curr_num += char_val;
      }
    }
    return curr_str;
  }
};
