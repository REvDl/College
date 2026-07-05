#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> pathsWithMaxScore(vector<string> &board) {
    int rows = board.size();
    int cols = board[0].size();
    long long MOD = 1e9 + 7;
    vector<vector<pair<long long, long long>>> dp(
        rows, vector<pair<long long, long long>>(cols, {-1, 0}));
    dp[rows - 1][cols - 1] = {0, 1};

    for (int i = rows - 1; i >= 0; --i) {
      for (int j = cols - 1; j >= 0; --j) {
        if (i == rows - 1 && j == cols - 1) {
          continue;
        }
        char ch = board[i][j];
        if (ch == 'X') {
          continue;
        }
        long long num = (ch == 'E' || ch == 'S') ? 0 : (ch - '0');
        long long max_sum = -1;
        long long path = 0;
        int directions[3][2] = {{i + 1, j}, {i, j + 1}, {i + 1, j + 1}};

        for (auto &dir : directions) {
          int nr = dir[0];
          int nc = dir[1];

          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            long long prev_sum = dp[nr][nc].first;
            long long prev_path = dp[nr][nc].second;

            if (prev_sum > max_sum) {
              max_sum = prev_sum;
              path = prev_path;
            } else if (prev_sum == max_sum && max_sum != -1) {
              path = (path + prev_path) % MOD;
            }
          }
        }

        if (max_sum != -1) {
          dp[i][j] = {max_sum + num, path};
        }
      }
    }

    long long final_sum = dp[0][0].first;
    long long final_path = dp[0][0].second;

    if (final_sum == -1) {
      return {0, 0};
    }

    return {static_cast<int>(final_sum % MOD),
            static_cast<int>(final_path % MOD)};
  }
};
