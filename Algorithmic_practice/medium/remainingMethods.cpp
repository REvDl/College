#include <numeric>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int>
  remainingMethods(int n, int k, std::vector<std::vector<int>> &invocations) {
    std::unordered_set<int> infected = {k};
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : invocations) {
      graph[edge[0]].push_back(edge[1]);
    }

    std::queue<int> q;
    q.push(k);
    std::vector<bool> visited(n, false);
    visited[k] = true;

    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (int b : graph[a]) {
        if (!visited[b]) {
          visited[b] = true;
          infected.insert(b);
          q.push(b);
        }
      }
    }

    for (const auto &edge : invocations) {
      int a = edge[0];
      int b = edge[1];
      if (infected.count(b) && !infected.count(a)) {
        std::vector<int> all_methods(n);
        std::iota(all_methods.begin(), all_methods.end(), 0);
        return all_methods;
      }
    }

    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
      if (!infected.count(i)) {
        result.push_back(i);
      }
    }
    return result;
  }
};
