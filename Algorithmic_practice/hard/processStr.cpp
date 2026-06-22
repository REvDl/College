#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  char processStr(string s, long long k) {
    int n = s.size();
    vector<long long> lengths(n, 0);
    long long curr_len = 0;

    for (int i = 0; i < n; ++i) {
      char chr = s[i];
      if (islower(static_cast<unsigned char>(chr))) {
        curr_len += 1;
      } else if (chr == '*') {
        curr_len = max(0LL, curr_len - 1);
      } else if (chr == '#') {
        curr_len *= 2;
      }
      lengths[i] = curr_len;
    }

    if (lengths.empty() || k >= lengths.back())
      return '.';

    for (int i = n - 1; i >= 0; --i) {
      char chr = s[i];
      curr_len = lengths[i];
      long long prev_len = (i > 0) ? lengths[i - 1] : 0;

      if (chr == '#') {
        if (k >= prev_len) {
          k %= prev_len;
        }
      } else if (chr == '%') {
        k = curr_len - 1 - k;
      } else if (islower(static_cast<unsigned char>(chr))) {
        if (k == curr_len - 1) {
          return chr;
        }
      }
    }

    return '.';
  }
};
