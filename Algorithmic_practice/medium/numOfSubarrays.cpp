#include <vector>

class Solution {
public:
  int numOfSubarrays(std::vector<int> &arr) {
    const int MOD = 1e9 + 7;
    long long res = 0;
    int even = 1, odd = 0;
    int curr_sum = 0;

    for (int num : arr) {
      curr_sum += num;
      if (curr_sum % 2 == 0) {
        even++;
        res = (res + odd) % MOD;
      } else {
        odd++;
        res = (res + even) % MOD;
      }
    }

    return static_cast<int>(res);
  }
};
