#include <string>

class Solution {

private:
  long long memo[20][2][11][11][2][20];
  std::string current_sum_str;
  long long getWavinessSum(int pos, bool tight, int lastDigit,
                           int secondLastDigit, bool is_leading_zero,
                           int count_waves) {
    if (pos == current_sum_str.length()) {
      return count_waves;
    }
    int last_index = (lastDigit == -1) ? 10 : lastDigit;
    int last_second_index = (secondLastDigit == -1) ? 10 : secondLastDigit;
    if (memo[pos][tight][last_index][last_second_index][is_leading_zero]
            [count_waves] != -1) {
      return memo[pos][tight][last_index][last_second_index][is_leading_zero]
                 [count_waves];
    }
    int limit = tight ? (current_sum_str[pos] - '0') : 9;
    long long waviness = 0;
    for (int digit = 0; digit <= limit; ++digit) {
      int current_w = 0;
      bool next_tight = tight && (digit == limit);
      bool next_leading = is_leading_zero && (digit == 0);
      if (!is_leading_zero && lastDigit != -1 && secondLastDigit != -1) {
        if (lastDigit > digit && secondLastDigit < lastDigit) {
          current_w++;
        } else if (lastDigit < digit && secondLastDigit > lastDigit) {
          current_w++;
        }
      }
      waviness += getWavinessSum(pos + 1, next_tight, next_leading ? -1 : digit,
                                 next_leading ? -1 : lastDigit, next_leading,
                                 count_waves + current_w);
    }
    return memo[pos][tight][last_index][last_second_index][is_leading_zero]
               [count_waves] = waviness;
  }
  long long clear_memo(long long num) {
    if (num < 0)
      return 0;
    current_sum_str = std::to_string(num);
    std::memset(memo, -1, sizeof(memo));
    return getWavinessSum(0, true, -1, -1, true, 0);
  }

public:
  long long totalWaviness(long long num1, long long num2) {
    return clear_memo(num2) - clear_memo(num1 - 1);
  }
};
