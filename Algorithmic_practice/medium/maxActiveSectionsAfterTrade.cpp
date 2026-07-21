#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int maxActiveSectionsAfterTrade(std::string s) {
    std::string t = "1" + s + "1";
    std::vector<std::pair<char, int>> length_array;
    int length = 1;

    for (size_t i = 1; i < t.length(); ++i) {
      if (t[i - 1] == t[i]) {
        length++;
      } else {
        length_array.push_back({t[i - 1], length});
        length = 1;
      }
    }
    if (!t.empty()) {
      length_array.push_back({t.back(), length});
    }

    int max_gain = 0;
    if (length_array.size() >= 3) {
      for (size_t i = 1; i < length_array.size() - 1; ++i) {
        char prev_char = length_array[i - 1].first;
        int prev_length = length_array[i - 1].second;
        char curr_char = length_array[i].first;
        char next_char = length_array[i + 1].first;
        int next_length = length_array[i + 1].second;

        if (curr_char == '1' && prev_char == '0' && next_char == '0') {
          max_gain = std::max(max_gain, prev_length + next_length);
        }
      }
    }

    int initial_ones = std::count(s.begin(), s.end(), '1');
    return initial_ones + max_gain;
  }
};
