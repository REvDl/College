#include <string>

class Solution {
public:
  int minAddToMakeValid(std::string s) {
    int count = 0;
    int open_bracke = 0;

    for (char c : s) {
      if (c == '(') {
        open_bracke += 1;
        count += 1;
      } else {
        if (open_bracke > 0) {
          open_bracke -= 1;
          count -= 1;
        } else {
          count += 1;
        }
      }
    }

    return count;
  }
};
