#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
  std::vector<int> assignTasks(std::vector<int> &servers,
                               std::vector<int> &tasks) {
    int n = servers.size();
    int m = tasks.size();
    std::vector<int> ans(m, 0);
    long long curr_time = 0;

    using Server = std::pair<int, int>;
    std::priority_queue<Server, std::vector<Server>, std::greater<Server>>
        free_server;

    for (int i = 0; i < n; ++i) {
      free_server.push({servers[i], i});
    }

    using BusyServer = std::tuple<long long, int, int>;
    std::priority_queue<BusyServer, std::vector<BusyServer>,
                        std::greater<BusyServer>>
        busy_server;

    for (int j = 0; j < m; ++j) {
      curr_time = std::max(curr_time, static_cast<long long>(j));

      if (free_server.empty() && !busy_server.empty() &&
          std::get<0>(busy_server.top()) > curr_time) {
        curr_time = std::get<0>(busy_server.top());
      }

      while (!busy_server.empty() &&
             std::get<0>(busy_server.top()) <= curr_time) {
        auto [time, weight, idx] = busy_server.top();
        busy_server.pop();
        free_server.push({weight, idx});
      }

      auto [weight, idx] = free_server.top();
      free_server.pop();

      ans[j] = idx;
      busy_server.push({curr_time + tasks[j], weight, idx});
    }

    return ans;
  }
};
