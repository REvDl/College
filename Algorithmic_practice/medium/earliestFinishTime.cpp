#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {
    int minLand = INT_MAX;
    int minWater = INT_MAX;
    for (int i = 0; i < landStartTime.size(); ++i) {
      minLand = min(minLand, landStartTime[i] + landDuration[i]);
    }
    for (int i = 0; i < waterStartTime.size(); ++i) {
      minWater = min(minWater, waterStartTime[i] + waterDuration[i]);
    }
    int finish_water = INT_MAX, finish_land = INT_MAX;
    for (int i = 0; i < waterStartTime.size(); ++i) {
      int start_water = max(minLand, waterStartTime[i]);
      finish_water = min(start_water + waterDuration[i], finish_water);
    }
    for (int j = 0; j < landStartTime.size(); ++j) {
      int start_land = max(minWater, landStartTime[j]);
      finish_land = min(start_land + landDuration[j], finish_land);
    }
    return min(finish_water, finish_land);
  }
};
