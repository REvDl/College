#include <vector>

class Solution {
public:
  std::vector<int> resultArray(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> arr1 = {nums[0]};
    std::vector<int> arr2 = {nums[1]};

    for (int i = 2; i < n; ++i) {
      if (arr1.back() > arr2.back()) {
        arr1.push_back(nums[i]);
      } else {
        std::vector<int> &target = arr2;
        arr2.push_back(nums[i]);
      }
    }

    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
  }
};
