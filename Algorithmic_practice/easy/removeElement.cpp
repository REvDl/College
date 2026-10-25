#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    erase_if(nums, [val](int num) { return num == val; });
    return nums.size();
  }
};
