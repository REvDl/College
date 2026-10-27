#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> createGrid(int m, int n) {
    std::vector<std::string> grid;
    grid.reserve(m);
    for (int i = 0; i < m - 1; ++i) {
      grid.push_back("." + std::string(n - 1, '#'));
    }
    grid.push_back(std::string(n, '.'));
    return grid;
  }
};
