#include <queue>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image,
                                          int sr, int sc, int color) {
    int comparison_color = image[sr][sc];
    if (comparison_color == color) {
      return image;
    }

    int rows = image.size();
    int cols = image[0].size();

    std::queue<std::pair<int, int>> queue;
    queue.push({sr, sc});
    image[sr][sc] = color;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!queue.empty()) {
      auto [r, c] = queue.front();
      queue.pop();

      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
            image[nr][nc] == comparison_color) {
          image[nr][nc] = color;
          queue.push({nr, nc});
        }
      }
    }

    return image;
  }
};
