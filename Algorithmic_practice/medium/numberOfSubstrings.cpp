#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int res = 0;
    int n = s.length();
    vector<int> idx_a, idx_b, idx_c;

    for (int idx = 0; idx < n; ++idx) {
      if (s[idx] == 'a')
        idx_a.push_back(idx);
      if (s[idx] == 'b')
        idx_b.push_back(idx);
      if (s[idx] == 'c')
        idx_c.push_back(idx);
    }

    int len_a = idx_a.size();
    int len_b = idx_b.size();
    int len_c = idx_c.size();
    int p_a = 0, p_b = 0, p_c = 0;
    for (size_t i = 0; i < n; ++i) {
      while (p_a < len_a && idx_a[p_a] < i) {
        p_a += 1;
      }
      while (p_b < len_b && idx_b[p_b] < i) {
        p_b += 1;
      }
      while (p_c < len_c && idx_c[p_c] < i) {
        p_c += 1;
      }
      if (p_a == len_a || p_b == len_b || p_c == len_c) {
        break;
      }
      int max_idx = max({idx_a[p_a], idx_b[p_b], idx_c[p_c]});
      res += n - max_idx;
    }
    return res;
  }
};
