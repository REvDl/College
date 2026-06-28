#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (size_t i = 1; i < arr.size(); ++i) {
      arr[i] = min(arr[i - 1] + 1, arr[i]);
    }
    return arr.back();
  }
};
