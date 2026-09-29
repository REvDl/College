#include <map>
#include <string>
#include <tuple>
#include <vector>

class Solution {
private:
  int rows;
  int cols;
  std::map<std::tuple<int, int, int>, bool> memo;

  bool dfs(int r, int c, int current_count_brace,
           const std::vector<std::vector<char>> &grid) {
    if (current_count_brace < 0) {
      return false;
    }
    if (r == rows - 1 && c == cols - 1) {
      return current_count_brace == 0;
    }

    std::tuple<int, int, int> state = {r, c, current_count_brace};
    if (memo.count(state)) {
      return memo[state];
    }

    if (r + 1 < rows) {
      if (dfs(r + 1, c, current_count_brace + (grid[r + 1][c] == '(' ? 1 : -1),
              grid)) {
        return memo[state] = true;
      }
    }
    if (c + 1 < cols) {
      if (dfs(r, c + 1, current_count_brace + (grid[r][c + 1] == '(' ? 1 : -1),
              grid)) {
        return memo[state] = true;
      }
    }

    return memo[state] = false;
  }

public:
  bool hasValidPath(std::vector<std::vector<char>> &grid) {
    rows = grid.size();
    cols = grid[0].size();
    memo.clear();

    if (grid[0][0] == ')') {
      return false;
    }

    return dfs(0, 0, 1, grid);
  }
};
