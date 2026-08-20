#include <string>

using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    int res = 0;
    for (char chr : s + t) {
      res ^= chr;
    }
    char find = static_cast<char>(res);
    return find;
  }
};
