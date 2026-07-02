#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
  bool findSafeWalk(vector<vector<int>> &grid, int health) {
    int m = grid.size();
    int n = grid[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> max_health(m, vector<int>(n, -1));
    int start_health = (grid[0][0] == 1) ? health - 1 : health;
    if (start_health < 1) {
      return false;
    }
    max_health[0][0] = start_health;
    priority_queue<tuple<int, int, int>> max_heap;
    max_heap.push({start_health, 0, 0});
    while (!max_heap.empty()) {
      auto [hp, r, c] = max_heap.top();
      max_heap.pop();
      if (r == m - 1 && c == n - 1) {
        return hp >= 1;
      }
      for (auto &[dr, dc] : directions) {
        int nr = r + dr;
        int nc = c + dc;
        if (0 <= nr && nr < m && 0 <= nc && nc < n) {
          int next_hp = hp - grid[nr][nc];
          if (next_hp > max_health[nr][nc]) {
            max_health[nr][nc] = next_hp;
            max_heap.push({next_hp, nr, nc});
          }
        }
      }
    }

    return false;
  }
};
