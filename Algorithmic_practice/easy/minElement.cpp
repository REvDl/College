#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minElement(vector<int> &nums) {
    int min_sum = nums[0];
    for (int num : nums) {
      int digit_sum = 0;
      while (num > 0) {
        digit_sum += num % 10;
        num /= 10;
      }
      min_sum = min(min_sum, digit_sum);
    }
    return min_sum;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {10, 12, 13, 14};
  cout << obj.minElement(nums) << endl;
}
