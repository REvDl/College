#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 3, 0);
    vector<int> stoneValue_padded = stoneValue;
    stoneValue_padded.insert(stoneValue_padded.end(), {0, 0, 0});

    for (int i = n - 1; i >= 0; --i) {
      int two_stones = stoneValue_padded[i] + stoneValue_padded[i + 1];
      int three_stones = two_stones + stoneValue_padded[i + 2];
      dp[i] = max({stoneValue_padded[i] - dp[i + 1], two_stones - dp[i + 2],
                   three_stones - dp[i + 3]});
    }

    string winner = "Tie";
    if (dp[0] > 0) {
      winner = "Alice";
    } else if (dp[0] < 0) {
      winner = "Bob";
    }
    return winner;
  }
};
