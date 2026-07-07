#include <numeric>
#include <vector>

class Solution {
public:
  long long sumAndMultiply(int n) {
    std::vector<int> x;
    while (n > 0) {
      int digit = n % 10;
      if (digit != 0) {
        x.push_back(digit);
      }
      n /= 10;
    }
    long long number = 0;
    for (int i = x.size() - 1; i >= 0; --i) {
      number = number * 10 + x[i];
    }
    long long sum_of_elements = 0;
    for (int digit : x) {
      sum_of_elements += digit;
    }
    return number * sum_of_elements;
  }
};
