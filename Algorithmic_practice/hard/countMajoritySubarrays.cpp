#include <vector>

using namespace std;

class Solution {
private:
  void update(int pos, int val, int tree_size, vector<int> &tree) {
    pos += tree_size;
    tree[pos] += val;
    while (pos > 1) {
      tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
      pos >>= 1;
    }
  }

  int query(int l, int r, int tree_size, vector<int> &tree) {
    int res = 0;
    l += tree_size;
    r += tree_size;
    while (l < r) {
      if (l & 1) {
        res += tree[l];
        l += 1;
      }
      if (r & 1) {
        r -= 1;
        res += tree[r];
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }

public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    int tree_size = 2 * n;
    vector<int> tree(tree_size * 2 + 2, 0);
    long long res = 0;
    update(n, 1, tree_size, tree);
    int current_sum = 0;

    for (int idx = 0; idx < n; ++idx) {
      current_sum += (nums[idx] == target ? 1 : -1);
      res += query(0, current_sum + n, tree_size, tree);
      update(current_sum + n, 1, tree_size, tree);
    }

    return res;
  }
};
