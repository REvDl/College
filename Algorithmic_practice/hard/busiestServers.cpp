#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> busiestServers(int k, std::vector<int> &arrival,
                                  std::vector<int> &load) {
    int n = arrival.size();
    std::set<int> free_servers;
    for (int i = 0; i < k; ++i) {
      free_servers.insert(i);
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        busy_servers;
    std::unordered_map<int, int> ans;
    int max_val = 0;

    for (int i = 0; i < n; ++i) {
      while (!busy_servers.empty() && busy_servers.top().first <= arrival[i]) {
        free_servers.insert(busy_servers.top().second);
        busy_servers.pop();
      }

      if (!free_servers.empty()) {
        auto it = free_servers.lower_bound(i % k);
        if (it == free_servers.end()) {
          it = free_servers.begin();
        }
        int server_idx = *it;
        ans[server_idx]++;
        max_val = std::max(max_val, ans[server_idx]);
        busy_servers.push({arrival[i] + load[i], server_idx});
        free_servers.erase(it);
      }
    }

    std::vector<int> result;
    for (auto const &[server, count] : ans) {
      if (count == max_val) {
        result.push_back(server);
      }
    }
    return result;
  }
};
