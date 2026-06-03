#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution_yesterday {
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

class Solution {
public:
  int get_earliest_end(vector<int> &StartTime, vector<int> &Duration) {
    int end = INT_MAX;
    for (int i = 0; i < StartTime.size(); ++i) {
      end = min(end, StartTime[i] + Duration[i]);
    }
    return end;
  };

  int solve_one_way(vector<int> &FirstStartTime, vector<int> &FirstDuration,
                    vector<int> &SecondStartTime, vector<int> &SecondDuration) {
    int min_end = get_earliest_end(FirstStartTime, FirstDuration);
    int earliest_end = INT_MAX;
    for (size_t i = 0; i < SecondStartTime.size(); ++i) {
      int start = max(min_end, SecondStartTime[i]);
      earliest_end = min(earliest_end, start + SecondDuration[i]);
    }
    return earliest_end;
  }

  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {
    return min(solve_one_way(landStartTime, landDuration, waterStartTime,
                             waterDuration),
               solve_one_way(waterStartTime, waterDuration, landStartTime,
                             landDuration));
  }
};
