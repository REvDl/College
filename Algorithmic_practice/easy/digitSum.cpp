#include <string>

using namespace std;

class Solution {
public:
  string digitSum(string s, int k) {
    int n = s.length();

    while (n > k) {
      int curr_sum = 0;
      string next_s = "";

      for (int i = 0; i < n; ++i) {
        curr_sum += s[i] - '0';

        if ((i + 1) % k == 0 || i == n - 1) {
          next_s += to_string(curr_sum);
          curr_sum = 0;
        }
      }

      s = next_s;
      n = s.length();
    }

    return s;
  }
};
