#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>> &restrictions) {
    restrictions.push_back({1, 0});
    restrictions.push_back({n, n - 1});
    sort(
        restrictions.begin(), restrictions.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    for (int i = 0; i < restrictions.size() - 1; ++i) {
      restrictions[i + 1][1] = min(
          restrictions[i + 1][1],
          restrictions[i][1] + (restrictions[i + 1][0] - restrictions[i][0]));
    }
    for (int i = restrictions.size() - 2; i >= 0; --i) {
      restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] +
                                                       (restrictions[i + 1][0] -
                                                        restrictions[i][0]));
    }
    int max_val = 0;
    for (int i = 0; i < restrictions.size() - 1; ++i) {
      int peak = (restrictions[i][1] + restrictions[i + 1][1] +
                  (restrictions[i + 1][0] - restrictions[i][0])) /
                 2;
      max_val = max(peak, max_val);
    }
    return max_val;
  }
};
