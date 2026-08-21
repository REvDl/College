#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
private:
  long long lcm(long long a, long long b) { return std::lcm(a, b); }

  void get_combinations(const std::vector<int> &coins, int index, int count,
                        long long current_lcm, long long x, long long &total) {
    if (index == coins.size()) {
      if (count > 0) {
        long long pieces = x / current_lcm;
        if (count % 2 == 1) {
          total += pieces;
        } else {
          total -= pieces;
        }
      }
      return;
    }

    get_combinations(coins, index + 1, count, current_lcm, x, total);

    long long next_lcm = lcm(current_lcm, coins[index]);
    if (next_lcm <= x) {
      get_combinations(coins, index + 1, count + 1, next_lcm, x, total);
    }
  }

  long long _count_x(long long x, const std::vector<int> &coins) {
    long long total = 0;
    get_combinations(coins, 0, 0, 1, x, total);
    return total;
  }

public:
  long long findKthSmallest(std::vector<int> &coins, int k) {
    long long left = 1;
    long long min_coin = *std::min_element(coins.begin(), coins.end());
    long long right = min_coin * k;

    while (left < right) {
      long long mid = left + (right - left) / 2;
      if (_count_x(mid, coins) < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return right;
  }
};
