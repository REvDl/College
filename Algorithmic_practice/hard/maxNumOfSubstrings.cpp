#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> maxNumOfSubstrings(std::string s) {
    std::unordered_map<char, std::pair<int, int>> indexes;
    for (int i = 0; i < s.length(); ++i) {
      char ch = s[i];
      if (indexes.find(ch) == indexes.end()) {
        indexes[ch] = {i, i};
      } else {
        indexes[ch].second = i;
      }
    }

    std::vector<std::pair<int, int>> indexes_substrings;
    for (auto const &[ch, bounds] : indexes) {
      int start = bounds.first;
      int end = bounds.second;
      int curr = start;
      while (curr <= end) {
        char curr_ch = s[curr];
        if (indexes[curr_ch].second > end) {
          end = indexes[curr_ch].second;
        }
        if (indexes[curr_ch].first < start) {
          start = indexes[curr_ch].first;
          curr = start;
        }
        curr++;
      }
      indexes_substrings.push_back({start, end});
    }

    std::sort(indexes_substrings.begin(), indexes_substrings.end(),
              [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                return a.second < b.second;
              });

    std::vector<std::pair<int, int>> res;
    if (!indexes_substrings.empty()) {
      res.push_back(indexes_substrings[0]);
    }

    for (size_t i = 1; i < indexes_substrings.size(); ++i) {
      int start = indexes_substrings[i].first;
      int end = indexes_substrings[i].second;
      if (start > res.back().second) {
        res.push_back({start, end});
      }
    }

    std::vector<std::string> result_strings;
    for (auto const &[start, end] : res) {
      result_strings.push_back(s.substr(start, end - start + 1));
    }

    return result_strings;
  }
};
