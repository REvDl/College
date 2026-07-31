#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minimumPushes(std::string word) {
    int pushes = 0;
    std::unordered_map<char, int> counter;

    for (char c : word) {
      counter[c]++;
    }

    std::vector<int> frequency;
    for (auto const &[key, val] : counter) {
      frequency.push_back(val);
    }

    std::sort(frequency.begin(), frequency.end(), std::greater<int>());

    for (int i = 0; i < frequency.size(); ++i) {
      pushes += (i / 8 + 1) * frequency[i];
    }

    return pushes;
  }
};
