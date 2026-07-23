#include <bit>
#include <vector>

class Solution {
public:
  int uniqueXorTriplets(std::vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return n;
    }
    return 1 << std::bit_width(static_cast<unsigned int>(n));
  }
};
