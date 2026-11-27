#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumSaleItems(vector<vector<int>> &items, int budget) {
    int n = items.size();
    vector<int> bonus(n, 0);

    for (int i = 0; i < n; ++i) {
      int curr = 1;
      for (int j = 0; j < n; ++j) {
        int factor_i = items[i][0];
        int factor_j = items[j][0];
        if (i != j) {
          if (factor_j % factor_i == 0) {
            curr += 1;
          }
        }
      }
      bonus[i] = curr;
    }

    vector<int> dp(budget + 1, 0);

    for (int i = 0; i < n; ++i) {
      int price = items[i][1];
      for (int b = budget; b >= price; --b) {
        dp[b] = max(dp[b], dp[b - price] + bonus[i]);
      }
      for (int b = price; b <= budget; ++b) {
        dp[b] = max(dp[b], dp[b - price] + 1);
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
