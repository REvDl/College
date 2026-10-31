#include <vector>

class Solution {
public:
  int uniquePaths(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    long long MOD = 1000000007;

    std::vector<std::vector<long long>> R(rows + 1,
                                          std::vector<long long>(cols + 1, 0));
    std::vector<std::vector<long long>> D(rows + 1,
                                          std::vector<long long>(cols + 1, 0));

    R[0][0] = 1;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 0) {
          long long total = (R[i][j] + D[i][j]) % MOD;
          R[i][j + 1] = (R[i][j + 1] + total) % MOD;
          D[i + 1][j] = (D[i + 1][j] + total) % MOD;
        } else {
          long long d_el = D[i][j];
          long long r_el = R[i][j];
          R[i][j + 1] = (R[i][j + 1] + d_el) % MOD;
          D[i + 1][j] = (D[i + 1][j] + r_el) % MOD;
        }
      }
    }

    return (R[rows - 1][cols - 1] + D[rows - 1][cols - 1]) % MOD;
  }
};
