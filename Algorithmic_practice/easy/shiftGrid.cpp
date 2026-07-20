#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid,
                                          int k) {
    int n = grid.size();
    int m = grid[0].size();
    int total_elements = n * m;

    std::vector<int> grid_flat(total_elements, 0);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int idx = (i * m + j + k) % total_elements;
        grid_flat[idx] = grid[i][j];
      }
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < total_elements; ++i) {
      matrix[i / m][i % m] = grid_flat[i];
    }

    return matrix;
  }
};
