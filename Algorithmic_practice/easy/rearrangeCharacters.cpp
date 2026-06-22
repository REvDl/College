#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    unordered_map<char, int> counts;
    unordered_map<char, int> target_counts;
    for (char c : s)
      counts[c]++;
    for (char c : target)
      target_counts[c]++;
    int min_element = INT_MAX;
    for (const auto &[char_s, char_t] : target_counts) {
      if (counts.find(char_s) == counts.end()) {
        return 0;
      }
      min_element = min(min_element, counts[char_s] / char_t);
    }
    return min_element;
  }
};
