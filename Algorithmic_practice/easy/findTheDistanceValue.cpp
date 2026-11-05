#include <cmath>
#include <vector>

class Solution {
public:
  int findTheDistanceValue(std::vector<int> &arr1, std::vector<int> &arr2,
                           int d) {
    int answer = 0;
    int n = arr1.size();
    int n2 = arr2.size();

    for (int i = 0; i < n; ++i) {
      bool exist = true;
      for (int j = 0; j < n2; ++j) {
        if (std::abs(arr1[i] - arr2[j]) <= d) {
          exist = false;
          break;
        }
      }
      if (exist) {
        answer += 1;
      }
    }
    return answer;
  }
};
