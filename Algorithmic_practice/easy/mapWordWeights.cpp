#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string mapWordWeights(vector<string> &words, vector<int> &weights) {
    string result(words.size(), ' ');
    for (size_t i = 0; i < words.size(); ++i) {
      int total = 0;
      for (char chr : words[i]) {
        int distance = chr - 'a';
        total += weights[distance];
      }
      result[i] = 'z' - (total % 26);
    }
    return result;
  }
};
