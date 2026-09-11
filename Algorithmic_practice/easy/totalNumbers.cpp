#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int totalNumbers(std::vector<int> &digits) {
    std::unordered_map<int, int> counts;
    for (int digit : digits) {
      counts[digit]++;
    }

    std::vector<int> truncated_digits;
    for (auto const &[digit, count] : counts) {
      int take = std::min(count, 3);
      for (int i = 0; i < take; ++i) {
        truncated_digits.push_back(digit);
      }
    }

    std::unordered_set<int> res;
    std::sort(truncated_digits.begin(), truncated_digits.end());

    do {
      if (truncated_digits[0] == 0) {
        continue;
      }
      int num = truncated_digits[0] * 100 + truncated_digits[1] * 10 +
                truncated_digits[2];
      if (num % 2 == 0) {
        res.insert(num);
      }
    } while (std::next_permutation(truncated_digits.begin(),
                                   truncated_digits.end()));

    return res.size();
  }
};
