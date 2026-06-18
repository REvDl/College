#include <algorithm>
#include <cmath>

class Solution {
public:
  double angleClock(int hour, int minutes) {
    int angle_min = minutes * 6;
    double angle_hour = (hour % 12 * 30) + (minutes * 0.5);
    double diff = abs(angle_hour - angle_min);
    return std::min(diff, 360 - diff);
  }
};
