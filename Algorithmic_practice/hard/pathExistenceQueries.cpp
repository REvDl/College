#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                   vector<vector<int>> &queries) {
    vector<pair<int, int>> sorted_num(n);
    for (int i = 0; i < n; ++i) {
      sorted_num[i] = {nums[i], i};
    }
    sort(sorted_num.begin(), sorted_num.end());
    vector<int> pos(n);
    for (int idx = 0; idx < n; ++idx) {
      pos[sorted_num[idx].second] = idx;
    }
    const int LOG = 18;
    vector<vector<int>> up(n + 1, vector<int>(LOG, n));
    int right = 0;
    for (int left = 0; left < n; ++left) {
      while (right < n &&
             sorted_num[right].first - sorted_num[left].first <= maxDiff) {
        right++;
      }
      up[left][0] = right - 1;
    }
    for (int k = 1; k < LOG; ++k) {
      for (int i = 0; i < n; ++i) {
        up[i][k] = up[up[i][k - 1]][k - 1];
      }
    }

    vector<int> ans;
    ans.reserve(queries.size());
    for (const auto &query : queries) {
      int u_orig = query[0];
      int v_orig = query[1];

      if (u_orig == v_orig) {
        ans.push_back(0);
        continue;
      }
      int u = pos[u_orig];
      int v = pos[v_orig];

      if (u > v) {
        swap(u, v);
      }
      if (up[u][LOG - 1] < v) {
        ans.push_back(-1);
        continue;
      }

      int curr = u;
      int steps = 0;
      for (int k = LOG - 1; k >= 0; --k) {
        if (up[curr][k] < v) {
          curr = up[curr][k];
          steps += (1 << k);
        }
      }
      steps += 1;
      curr = up[curr][0];
      if (curr >= v) {
        ans.push_back(steps);
      } else {
        ans.push_back(-1);
      }
    }
    return ans;
  }
};
