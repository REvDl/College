#include <algorithm>
#include <cmath>

class Solution {
public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                    int x2, int y2) {
    int position_x = std::max(x1, std::min(xCenter, x2));
    int position_y = std::max(y1, std::min(yCenter, y2));
    int distantioc = std::hypot(position_x - xCenter, position_y - yCenter);
    if (distantioc <= radius)
      return true;
    return false;
  }
};
