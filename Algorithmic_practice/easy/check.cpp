#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  bool check(vector<int> &nums) {
    int count = 0, n = ssize(nums);
    for (int i = 0; i < n; ++i) {
      if (nums[i] > nums[(i + 1) % n]) {
        count += 1;
      }
    }
    if (count <= 1)
      return true;
    else
      return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {3, 4, 5, 1, 2};
  cout << boolalpha << obj.check(nums) << endl;
}
