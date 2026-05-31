#include <vector>

using namespace std;

class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    long int result = 0;
    for (size_t i = 0; i < timeSeries.size() - 1; ++i) {
      int diff = timeSeries[i + 1] - timeSeries[i];
      if (diff >= duration) {
        result += duration;
      } else
        result += diff;
    }
    return result += duration;
  }
};
