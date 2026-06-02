#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {
    int finish = INT_MAX;
    for (int i = 0; i < landStartTime.size(); ++i) {
      for (int j = 0; j < waterStartTime.size(); ++j) {
        int land_F = landStartTime[i] + landDuration[i];
        int water_F = waterStartTime[j] + waterDuration[j];

        int start_land = max(land_F, waterStartTime[j]);
        int start_water = max(water_F, landStartTime[i]);

        finish = min({start_land + waterDuration[j],
                      start_water + landDuration[i], finish});
      }
    }
    return finish;
  }
};
