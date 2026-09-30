#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> maxDepthAfterSplit(std::string seq) {
    std::vector<int> res;
    int brace = 0;
    for (char c : seq) {
      if (c == '(') {
        res.push_back(brace % 2);
        brace++;
      } else {
        brace--;
        res.push_back(brace % 2);
      };
    };
    return res;
  };
};
