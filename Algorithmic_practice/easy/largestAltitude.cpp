#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    vector<int> pref_sum(gain.size() + 1, 0);
    for (int i = 0; i < gain.size(); ++i) {
      pref_sum[i + 1] = pref_sum[i] + gain[i];
    }
    return *max_element(pref_sum.begin(), pref_sum.end());
  }
};
