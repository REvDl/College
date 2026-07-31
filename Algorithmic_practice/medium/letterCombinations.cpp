#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
  std::unordered_map<char, std::string> phone_map = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return {};
    }

    std::queue<std::string> queue;
    queue.push("");

    for (char digit : digits) {
      std::string letters = phone_map[digit];
      int len_q = queue.size();

      for (int i = 0; i < len_q; ++i) {
        std::string current = queue.front();
        queue.pop();

        for (char letter : letters) {
          queue.push(current + letter);
        }
      }
    }

    std::vector<std::string> res;
    while (!queue.empty()) {
      res.push_back(queue.front());
      queue.pop();
    }

    return res;
  }
};
