#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> countServers(int n, std::vector<std::vector<int>> &logs,
                                int x, std::vector<int> &queries) {
    std::vector<std::pair<int, int>> sorted_queries;
    sorted_queries.reserve(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      sorted_queries.push_back({queries[i], i});
    }
    std::sort(sorted_queries.begin(), sorted_queries.end());

    std::sort(logs.begin(), logs.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[1] < b[1];
              });

    std::vector<int> arr(queries.size(), 0);
    std::unordered_map<int, int> count;
    int active_servers = 0;
    int left = 0, right = 0;

    for (const auto &[server_time, original_index] : sorted_queries) {
      while (right < logs.size() && logs[right][1] <= server_time) {
        count[logs[right][0]]++;
        if (count[logs[right][0]] == 1) {
          active_servers++;
        }
        right++;
      }
      while (left < logs.size() && logs[left][1] < (server_time - x)) {
        count[logs[left][0]]--;
        if (count[logs[left][0]] == 0) {
          active_servers--;
        }
        left++;
      }
      arr[original_index] = n - active_servers;
    }

    return arr;
  }
};
