#include <string>
#include <vector>

class Solution {
public:
  int numOfStrings(std::vector<std::string> &patterns, std::string word) {
    int res = 0;
    for (auto const pattern : patterns) {
      if (word.find(pattern) != std::string::npos) {
        res += 1;
      }
    }
    return res;
  }
};
