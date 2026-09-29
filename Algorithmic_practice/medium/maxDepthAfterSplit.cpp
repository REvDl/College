#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> maxDepthAfterSplit(std::string seq) {
    bool open_brace = false;
    bool closed_brace = false;
    std::vector<int> res;

    for (char c : seq) {
      if (c == '(' && open_brace) {
        res.push_back(1);
        open_brace = false;
      } else if (c == '(' && !open_brace) {
        res.push_back(0);
        open_brace = true;
      } else if (c == ')' && closed_brace) {
        res.push_back(1);
        closed_brace = false;
      } else if (c == ')' && !closed_brace) {
        res.push_back(0);
        closed_brace = true;
      }
    }
    return res;
  }
};
