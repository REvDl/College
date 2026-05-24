#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int maxJumps(vector<int> &arr, int d) {
    int n = ssize(arr);
    vector<int> dp(n, 0);
    vector<int> sorted_index(n);
    iota(sorted_index.begin(), sorted_index.end(), 0);
    sort(sorted_index.begin(), sorted_index.end(),
         [&](int a, int b) { return arr[a] < arr[b]; });
    for (int i : sorted_index) {
      int r_j = i + 1;
      dp[i] = 1;
      while (r_j <= n - 1 && (r_j - i) <= d && arr[r_j] < arr[i]) {
        dp[r_j] = max(dp[i], 1 + dp[r_j]);
        r_j += 1;
      }
      int l_j = i - 1;
      while (l_j >= 0 && (i - l_j) <= d && arr[l_j] < arr[i]) {
        dp[l_j] = max(dp[i], 1 + dp[l_j]);
        l_j -= 1;
      }
    }
    int max_jump = *max_element(dp.begin(), dp.end());
    return max_jump;
  }
};

int main() {
  Solution obj;
  vector<int> arr = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
  int d = 2;
  cout << boolalpha << obj.maxJumps(arr, d);
}
