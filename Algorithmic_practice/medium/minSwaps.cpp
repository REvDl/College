#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
  struct Node {
    int value;
    int digit_sum;
  };

  int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }

public:
  int minSwaps(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
      nodes[i] = {nums[i], getDigitSum(nums[i])};
    }

    std::sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b) {
      if (a.digit_sum != b.digit_sum) {
        return a.digit_sum < b.digit_sum;
      }
      return a.value < b.value;
    });

    std::unordered_map<int, int> target_pos;
    for (int i = 0; i < n; ++i) {
      target_pos[nodes[i].value] = i;
    }

    int res = 0;
    int i = 0;
    while (i < n) {
      int num = nums[i];
      if (i != target_pos[num]) {
        std::swap(nums[i], nums[target_pos[num]]);
        res++;
      } else {
        i++;
      }
    }
    return res;
  }
};
