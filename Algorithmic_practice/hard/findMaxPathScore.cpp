#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
                       long long k) {
    int n = online.size();
    vector<vector<pair<int, long long>>> graph(n);
    for (const auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      long long cost = edge[2];
      graph[u].push_back({v, cost});
    }

    vector<int> in_degree(n, 0);
    for (const auto &edge : edges) {
      int v = edge[1];
      in_degree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }

    vector<int> topo_order;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      topo_order.push_back(curr);

      for (const auto &neighbor_pair : graph[curr]) {
        int neighbor = neighbor_pair.first;
        in_degree[neighbor]--;
        if (in_degree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    const long long INF = 1e18;

    auto check = [&](long long min_allowed_edge) -> bool {
      vector<long long> dp(n, INF);
      dp[0] = 0;

      for (int curr : topo_order) {
        if (dp[curr] == INF)
          continue;

        for (const auto &neighbor_pair : graph[curr]) {
          int neighbor = neighbor_pair.first;
          long long cost = neighbor_pair.second;

          if (!online[neighbor] || cost < min_allowed_edge)
            continue;

          long long new_cost = dp[curr] + cost;
          if (new_cost <= k && new_cost < dp[neighbor]) {
            dp[neighbor] = new_cost;
          }
        }
      }
      return dp[n - 1] <= k;
    };

    set<long long> unique_costs;
    for (const auto &edge : edges) {
      unique_costs.insert(edge[2]);
    }
    vector<long long> all_costs(unique_costs.begin(), unique_costs.end());
    if (all_costs.empty())
      return -1;

    int left = 0;
    int right = all_costs.size() - 1;
    long long ans = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      long long mid_cost = all_costs[mid];

      if (check(mid_cost)) {
        ans = mid_cost;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return ans;
  }
};
int main() {
  Solution obj;
  vector<vector<int>> edges = {{0, 1, 7}, {1, 4, 5}, {0, 2, 6},
                               {2, 3, 6}, {3, 4, 2}, {2, 4, 6}};
  vector<bool> online = {true, true, true, false, true};
  int k = 12;

  cout << obj.findMaxPathScore(edges, online, k) << endl;

  return 0;
}
