#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> gcdValues(std::vector<int> &nums,
                             std::vector<long long> &queries) {
    int max_element = *std::max_element(nums.begin(), nums.end());
    std::vector<long long> counts(max_element + 1, 0);
    for (int num : nums) {
      counts[num]++;
    }

    std::vector<long long> count_nod(max_element + 1, 0);
    for (int g = max_element; g >= 1; --g) {
      long long total_m = 0;
      for (int j = g; j <= max_element; j += g) {
        total_m += counts[j];
      }

      long long total_p = (total_m * (total_m - 1)) / 2;
      for (int j = g * 2; j <= max_element; j += g) {
        total_p -= count_nod[j];
      }
      count_nod[g] = total_p;
    }
    std::vector<long long> prefix_sum(max_element + 1, 0);
    for (int i = 1; i <= max_element; ++i) {
      prefix_sum[i] = prefix_sum[i - 1] + count_nod[i];
    }

    std::vector<int> answer;
    answer.reserve(queries.size());

    for (long long query : queries) {
      auto it = std::upper_bound(prefix_sum.begin(), prefix_sum.end(), query);
      int idx = std::distance(prefix_sum.begin(), it);
      answer.push_back(idx);
    }

    return answer;
  }
};
