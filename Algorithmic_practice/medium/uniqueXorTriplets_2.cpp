#include <unordered_set>
#include <vector>

class Solution {
public:
  int uniqueXorTriplets(std::vector<int> &nums) {
    int n = nums.size();
    std::unordered_set<int> unique_xor_pair;

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        unique_xor_pair.insert(nums[i] ^ nums[j]);
      }
    }

    std::unordered_set<int> result_xor;
    for (int xor_val : unique_xor_pair) {
      for (int num : nums) {
        result_xor.insert(xor_val ^ num);
      }
    }

    return result_xor.size();
  }
};
