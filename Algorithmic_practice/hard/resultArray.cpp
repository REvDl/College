#include <algorithm>
#include <vector>

using namespace std;

class SegmentTree {
private:
  struct Node {
    long long prod;
    vector<long long> rem;
  };

  int n;
  long long k;
  vector<long long> data;
  vector<Node> tree;

  Node neutral_element() { return {1, vector<long long>(k, 0)}; }

  void merge_to_left(Node &left, const Node &right) {
    long long parent_prod = (left.prod * right.prod) % k;
    vector<long long> next_rem(k, 0);

    for (int x = 0; x < k; ++x) {
      next_rem[x] += left.rem[x];
    }

    for (int j = 0; j < k; ++j) {
      long long new_rem = (left.prod * j) % k;
      next_rem[new_rem] += right.rem[j];
    }

    left.prod = parent_prod;
    left.rem = move(next_rem);
  }

  void merge_nodes(Node &parent, const Node &left, const Node &right) {
    parent.prod = (left.prod * right.prod) % k;
    fill(parent.rem.begin(), parent.rem.end(), 0);

    for (int x = 0; x < k; ++x) {
      parent.rem[x] += left.rem[x];
    }

    for (int j = 0; j < k; ++j) {
      long long new_rem = (left.prod * j) % k;
      parent.rem[new_rem] += right.rem[j];
    }
  }

  void build(int node, int start, int end) {
    if (start == end) {
      long long val = data[start] % k;
      tree[node].prod = val;
      tree[node].rem[val] = 1;
      return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    merge_nodes(tree[node], tree[2 * node], tree[2 * node + 1]);
  }

  void update_tree(int node, int start, int end, int idx, long long val) {
    if (start == end) {
      fill(tree[node].rem.begin(), tree[node].rem.end(), 0);
      val = val % k;
      tree[node].prod = val;
      tree[node].rem[val] = 1;
      return;
    }
    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
      update_tree(2 * node, start, mid, idx, val);
    } else {
      update_tree(2 * node + 1, mid + 1, end, idx, val);
    }
    merge_nodes(tree[node], tree[2 * node], tree[2 * node + 1]);
  }

  void query_tree(int node, int start, int end, int l, int r, Node &ans) {
    if (r < start || end < l) {
      return;
    }
    if (l <= start && end <= r) {
      if (ans.prod == -1) {
        ans = tree[node];
      } else {
        merge_to_left(ans, tree[node]);
      }
      return;
    }
    int mid = start + (end - start) / 2;
    query_tree(2 * node, start, mid, l, r, ans);
    query_tree(2 * node + 1, mid + 1, end, l, r, ans);
  }

public:
  SegmentTree(const vector<long long> &input_data, long long mod_k) {
    data = input_data;
    n = data.size();
    k = mod_k;
    tree.resize(4 * n, {0, vector<long long>(k, 0)});
    if (n > 0) {
      build(1, 0, n - 1);
    }
  }

  void update(int idx, long long val) { update_tree(1, 0, n - 1, idx, val); }

  long long query(int l, int r, int x) {
    Node ans;
    ans.prod = -1;
    ans.rem.resize(k, 0);

    query_tree(1, 0, n - 1, l, r, ans);

    if (ans.prod == -1)
      return 0;
    return ans.rem[x];
  }
};

class Solution {
public:
  vector<int> resultArray(vector<int> &nums, int k,
                          vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> ans;
    ans.reserve(queries.size());

    vector<long long> long_nums(nums.begin(), nums.end());
    SegmentTree tree_obj(long_nums, static_cast<long long>(k));

    for (const auto &q : queries) {
      int idx = q[0];
      long long val = q[1];
      int start = q[2];
      int x = q[3];

      tree_obj.update(idx, val);
      long long res = tree_obj.query(start, n - 1, x);
      ans.push_back(static_cast<int>(res));
    }

    return ans;
  }
};
