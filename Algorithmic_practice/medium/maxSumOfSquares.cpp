#include <string>

class Solution {
public:
  std::string maxSumOfSquares(int num, int sum_leetcode) {
    std::string nines(sum_leetcode / 9, '9');
    int rem = sum_leetcode % 9;

    if (rem != 0) {
      nines += std::to_string(rem);
    }

    if (nines.length() > static_cast<size_t>(num)) {
      return "";
    }

    if (nines.length() < static_cast<size_t>(num)) {
      nines.append(num - nines.length(), '0');
    }

    return nines;
  }
};
