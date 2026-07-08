#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
    long long MOD = 1000000007;
    int n = s.length();
    vector<long long> prefix_sum(n + 1, 0);
    vector<long long> pref_val(n + 1, 0);
    vector<int> pref_len(n + 1, 0);
    vector<long long> powers(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
      powers[i] = (powers[i - 1] * 10) % MOD;
    }
    for (int i = 0; i < n; ++i) {
      int x = s[i] - '0';
      prefix_sum[i + 1] = prefix_sum[i] + x;

      if (x != 0) {
        pref_val[i + 1] = (pref_val[i] * 10 + x) % MOD;
        pref_len[i + 1] = pref_len[i] + 1;
      } else {
        pref_val[i + 1] = pref_val[i];
        pref_len[i + 1] = pref_len[i];
      }
    }

    vector<int> ans;
    ans.reserve(queries.size());
    for (const auto &query : queries) {
      int l = query[0];
      int r = query[1];

      int k = pref_len[r + 1] - pref_len[l];
      long long x_val =
          (pref_val[r + 1] - (pref_val[l] * powers[k]) % MOD + MOD) % MOD;
      long long sum_range = (prefix_sum[r + 1] - prefix_sum[l]) % MOD;
      ans.push_back((x_val * sum_range) % MOD);
    }
    return ans;
  }
};
