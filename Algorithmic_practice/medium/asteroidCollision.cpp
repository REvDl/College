#include <cmath>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    deque<int> stack;
    for (int asteroid : asteroids) {
      bool destroyed = false;
      while (!stack.empty() && asteroid < 0 and stack.back() > 0) {
        int abs_asteroid = abs(asteroid);
        if (abs_asteroid > stack.back()) {
          stack.pop_back();
        } else if (abs_asteroid == stack.back()) {
          stack.pop_back();
          destroyed = true;
          break;
        } else {
          destroyed = true;
          break;
        }
      }
      if (!destroyed) {
        stack.push_back(asteroid);
      }
    }
    return vector<int>(stack.begin(), stack.end());
  }
};
