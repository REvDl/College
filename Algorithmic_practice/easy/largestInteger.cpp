#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int largestInteger(std::vector<int> &nums, int k) {
    int n = nums.size();
    std::unordered_map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }

    std::vector<int> max_elements;

    if (k == n) {
      return *std::max_element(nums.begin(), nums.end());
    } else if (k == 1) {
      for (int num : nums) {
        if (count[num] == 1) {
          max_elements.push_back(num);
        }
      }
    } else {
      int left = nums.front();
      int right = nums.back();

      if (count[left] == 1) {
        max_elements.push_back(left);
      }
      if (count[right] == 1) {
        max_elements.push_back(right);
      }
    }

    if (max_elements.empty()) {
      return -1;
    }
    return *std::max_element(max_elements.begin(), max_elements.end());
  }
};
