#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = ssize(s), farthest = 0;
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
      if (!dp[i])
        continue;
      int j = max(i + minJump, farthest);
      while (j <= min(i + maxJump, n - 1)) {
        if (s[j] == '0')
          dp[j] = true;
        j += 1;
      };
      farthest = j;
    }
    return dp[n - 1];
  }
};

int main() {
  Solution obj;
  string s = "011010";
  int minJump = 2, maxJump = 3;
  cout << boolalpha << obj.canReach(s, minJump, maxJump) << endl;
}
