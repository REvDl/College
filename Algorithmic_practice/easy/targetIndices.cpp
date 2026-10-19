#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> targetIndices(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        res.push_back(i);
      }
    }
    return res;
  };
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 5, 2, 3};
  int target = 2;
  vector<int> result = obj.targetIndices(nums, target);
  for (const auto &num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
