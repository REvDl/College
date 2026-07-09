#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                    vector<vector<int>> &queries) {
    vector<int> groupd_id(n, 0);
    int id_count = 0;
    for (size_t i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] > maxDiff) {
        id_count++;
      }
      groupd_id[i] = id_count;
    }
    vector<bool> ans;
    ans.reserve(groupd_id.size());
    for (const auto &query : queries) {
      int ui = query[0], vi = query[1];
      ans.push_back(groupd_id[ui] == groupd_id[vi]);
    }
    return ans;
  }
};
