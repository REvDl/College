#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    int K = r - l + 1;
    long long MOD = pow(10, 9) + 7;
    vector<long long> dp0(K, 1);
    vector<long long> dp1(K, 1);
    for (int i = 2; i < n + 1; ++i) {
      vector<long long> next_dp0(K, 0);
      vector<long long> next_dp1(K, 0);
      long long pref0 = 0;
      for (int x = 0; x < K; ++x) {
        next_dp1[x] = pref0;
        pref0 = (pref0 + dp0[x]) % MOD;
      }
      long long suff1 = 0;
      for (int x = K - 1; x >= 0; --x) {
        next_dp0[x] = suff1;
        suff1 = (suff1 + dp1[x]) % MOD;
      }
      dp0 = next_dp0;
      dp1 = next_dp1;
    }
    return ((accumulate(dp0.begin(), dp0.end(), 0LL) % MOD) +
            (accumulate(dp1.begin(), dp1.end(), 0LL)) % MOD) %
           MOD;
  }
};
