#include <vector>

class Solution {
public:
  int countServers(std::vector<std::vector<int>> &grid) {
    int r = grid.size();
    int c = grid[0].size();
    int res = 0;

    std::vector<int> row_has_one(r, 0);
    std::vector<int> cols_with_ones(c, 0);

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (grid[i][j] == 1) {
          row_has_one[i]++;
          cols_with_ones[j]++;
        }
      }
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (grid[i][j] == 1 && (row_has_one[i] > 1 || cols_with_ones[j] > 1)) {
          res++;
        }
      }
    }

    return res;
  }
};
