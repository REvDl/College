#include <unordered_map>
#include <vector>

class SegmentTree {
public:
  int n;
  std::vector<long long> tree;
  std::vector<long long> lazy;
  std::vector<long long> square;

  SegmentTree(const std::vector<int> &data) {
    n = data.size();
    tree.assign(n * 4, 0);
    lazy.assign(n * 4, 0);
    square.assign(n * 4, 0);
  }

  void push(int v, int tl, int tr) {
    if (lazy[v] == 0) {
      return;
    }
    int tm = tl + (tr - tl) / 2;
    update(2 * v, tl, tm, tl, tm, lazy[v]);
    update(2 * v + 1, tm + 1, tr, tm + 1, tr, lazy[v]);
    lazy[v] = 0;
  }

  void update(int v, int tl, int tr, int l, int r, long long val) {
    if (tl > r || tr < l) {
      return;
    }
    if (l <= tl && tr <= r) {
      long long length = tr - tl + 1;
      square[v] = square[v] + 2 * val * tree[v] + val * val * length;
      tree[v] += val * length;
      lazy[v] += val;
      return;
    }
    push(v, tl, tr);
    int tm = tl + (tr - tl) / 2;
    update(2 * v, tl, tm, l, r, val);
    update(2 * v + 1, tm + 1, tr, l, r, val);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
    square[v] = square[v * 2] + square[v * 2 + 1];
  }
};

class Solution {
public:
  int sumCounts(std::vector<int> &nums) {
    long long MOD = 1000000007;
    long long res = 0;
    int n = nums.size();
    SegmentTree tree(nums);
    std::unordered_map<int, int> last_pos;

    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      int left = 0;
      if (last_pos.find(num) != last_pos.end()) {
        left = last_pos[num] + 1;
      } else {
        left = 0;
      }
      tree.update(1, 0, n - 1, left, i, 1);
      res = (res + tree.square[1]) % MOD;
      last_pos[num] = i;
    }
    return res;
  }
};
