#include <string>

using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    int res = 0;
    const size_t n = word.size();
    for (int i = 0; i < n; ++i) {
      res += i / 8 + 1;
    }
    return res;
  }
};
