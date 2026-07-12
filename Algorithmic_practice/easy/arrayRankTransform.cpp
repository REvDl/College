#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> arrayRankTransform(std::vector<int> &arr) {
    std::unordered_map<int, int> nums;
    int count = 1;
    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());
    for (int num : sorted_arr) {
      if (!nums.contains(num)) {
        nums[num] = count;
        count++;
      }
    }
    std::vector<int> result;
    result.reserve(arr.size());
    for (int num : arr) {
      result.push_back(nums[num]);
    }
    return result;
  }
};
