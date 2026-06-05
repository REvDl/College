#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class SegmentTree {
public:
  static const int MAXX = 50000;
  vector<int> tree;
  SegmentTree() { tree.assign(4 * MAXX + 1, 0); }
  void update(int curr_idx, int l, int r, int idx, int val) {
    if (l == r) {
      tree[curr_idx] = val;
      return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
      update(curr_idx * 2, l, mid, idx, val);
    } else {
      update(curr_idx * 2 + 1, mid + 1, r, idx, val);
    }
    tree[curr_idx] = max(tree[2 * curr_idx], tree[2 * curr_idx + 1]);
  }

  int query(int curr_idx, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) {
      return 0;
    }
    if (ql <= l && r <= qr) {
      return tree[curr_idx];
    }
    int mid = l + (r - l) / 2;
    int left_res = query(2 * curr_idx, l, mid, ql, qr);
    int right_res = query(2 * curr_idx + 1, mid + 1, r, ql, qr);
    return max(left_res, right_res);
  }
};

class Solution {
public:
  vector<bool> getResults(vector<vector<int>> &queries) {
    set<int> sorted_set;
    sorted_set.insert(0);
    SegmentTree segment;
    for (const auto &query : queries) {
      if (query[0] == 1) {
        sorted_set.insert(query[1]);
      }
    }
    int prev_pos = 0;
    for (int pos : sorted_set) {
      if (pos == 0)
        continue;
      segment.update(1, 0, segment.MAXX, pos, pos - prev_pos);
      prev_pos = pos;
    }
    vector<bool> ans;
    ans.reserve(queries.size());
    for (int i = queries.size() - 1; i >= 0; --i) {
      if (queries[i][0] == 2) {
        int x = queries[i][1];
        int sz = queries[i][2];
        auto it = sorted_set.upper_bound(x);
        it = prev(it);
        int left_pos = *it;
        int res_tree = segment.query(1, 0, segment.MAXX, 0, left_pos);
        int tail = x - left_pos;
        if (max(tail, res_tree) >= queries[i][2]) {
          ans.push_back(true);
        } else
          ans.push_back(false);
      } else {
        int x = queries[i][1];
        auto it = sorted_set.find(x);
        auto left_it = prev(it);
        auto right_it = next(it);
        int left_pos = *left_it;
        segment.update(1, 0, segment.MAXX, x, 0);
        if (right_it != sorted_set.end()) {
          int right_pos = *right_it;
          segment.update(1, 0, segment.MAXX, right_pos, right_pos - left_pos);
        }
        sorted_set.erase(x);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
