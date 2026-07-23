#include <queue>
#include <vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<bool>> visited(rows,
                                           std::vector<bool>(cols, false));

    auto bfs = [&](int start_r, int start_c) {
      std::queue<std::pair<int, int>> queue;
      queue.push({start_r, start_c});

      int dr[] = {0, 0, 1, -1};
      int dc[] = {1, -1, 0, 0};

      while (!queue.empty()) {
        auto [r, c] = queue.front();
        queue.pop();

        for (int i = 0; i < 4; ++i) {
          int nr = r + dr[i];
          int nc = c + dc[i];

          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
              !visited[nr][nc] && grid[nr][nc] == '1') {
            visited[nr][nc] = true;
            queue.push({nr, nc});
          }
        }
      }
    };

    int ans = 0;
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (grid[r][c] == '1' && !visited[r][c]) {
          ans++;
          visited[r][c] = true;
          bfs(r, c);
        }
      }
    }
    return ans;
  }
};
