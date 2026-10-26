#include <vector>

class Solution {
public:
  long long countIslands(std::vector<std::vector<int>> &grid, int k) {
    if (grid.empty() || grid[0].empty())
      return 0;

    long long count_islands = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        long long res = dfs(grid, r, c, rows, cols);
        if (res != 0 && res % k == 0) {
          count_islands++;
        }
      }
    }

    return count_islands;
  }

private:
  long long dfs(std::vector<std::vector<int>> &grid, int r, int c, int rows,
                int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
      return 0;
    }

    long long curr = grid[r][c];
    grid[r][c] = 0;

    return curr + dfs(grid, r + 1, c, rows, cols) +
           dfs(grid, r, c + 1, rows, cols) + dfs(grid, r - 1, c, rows, cols) +
           dfs(grid, r, c - 1, rows, cols);
  }
};
