#include <vector>

class Solution {
private:
  int rows, cols;

  void dfs(int r, int c, std::vector<std::vector<int>> &grid) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
      return;
    }
    grid[r][c] = 1;
    dfs(r + 1, c, grid);
    dfs(r, c + 1, grid);
    dfs(r - 1, c, grid);
    dfs(r, c - 1, grid);
  }

public:
  int closedIsland(std::vector<std::vector<int>> &grid) {
    if (grid.empty() || grid[0].empty())
      return 0;

    rows = grid.size();
    cols = grid[0].size();
    int count_islands = 0;

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) &&
            grid[r][c] == 0) {
          dfs(r, c, grid);
        }
      }
    }

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (grid[r][c] == 0) {
          count_islands++;
          dfs(r, c, grid);
        }
      }
    }

    return count_islands;
  }
};
