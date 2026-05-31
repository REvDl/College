#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
    sort(asteroids.begin(), asteroids.end());
    long long current_mass = mass;
    for (int asteroid : asteroids) {
      if (current_mass < asteroid)
        return false;
      current_mass += asteroid;
    }
    return true;
  }
};
int main() {
  Solution obj;
  vector<int> ast = {3, 9, 19, 5, 21};
  cout << boolalpha << obj.asteroidsDestroyed(10, ast) << endl;
}
