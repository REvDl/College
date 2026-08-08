#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> validSequence(std::string word1, std::string word2) {
    int n = word1.length();
    int m = word2.length();
    std::vector<int> last(m + 1, -1);
    last[m] = n;

    int j = m - 1;
    for (int i = n - 1; i >= 0; --i) {
      if (j >= 0 && word1[i] == word2[j]) {
        last[j] = i;
        j--;
      }
    }

    std::vector<int> res;
    j = 0;
    bool chg = false;

    for (int i = 0; i < n; ++i) {
      if (j == m) {
        break;
      }
      if (word1[i] == word2[j]) {
        if (!chg || i < last[j + 1]) {
          res.push_back(i);
          j++;
        }
      } else {
        if (!chg && (j == m - 1 || i < last[j + 1])) {
          res.push_back(i);
          chg = true;
          j++;
        }
      }
    }

    return res.size() == m ? res : std::vector<int>();
  }
};
