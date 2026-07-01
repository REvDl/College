#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<pair<int, int>> queue;

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (grid[r][c] == 1) {
          dist[r][c] = 0;
          queue.push({r, c});
        }
      }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!queue.empty()) {
      auto [r, c] = queue.front();
      queue.pop();

      for (auto [dr, dc] : directions) {
        int nr = dr + r;
        int nc = dc + c;

        if (0 <= nr && nr < rows && 0 <= nc && nc < cols &&
            dist[nr][nc] == -1) {
          dist[nr][nc] = dist[r][c] + 1;
          queue.push({nr, nc});
        }
      }
    }
    priority_queue<tuple<int, int, int>> max_heap;
    max_heap.push({dist[0][0], 0, 0});
    vector<vector<int>> max_safeness(rows, vector<int>(cols, -1));
    max_safeness[0][0] = dist[0][0];
    while (!max_heap.empty()) {
      auto [safe, r, c] = max_heap.top();
      max_heap.pop();
      if (r == rows - 1 && c == cols - 1) {
        return safe;
      }
      for (auto [dr, dc] : directions) {
        int nr = dr + r;
        int nc = dc + c;

        if (0 <= nr && nr < rows && 0 <= nc && nc < cols) {
          int next_safe = min(safe, dist[nr][nc]);

          if (next_safe > max_safeness[nr][nc]) {
            max_safeness[nr][nc] = next_safe;
            max_heap.push({next_safe, nr, nc});
          }
        }
      }
    }
    return 0;
  }
};
