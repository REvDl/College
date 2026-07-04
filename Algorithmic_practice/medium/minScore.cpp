#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto &road : roads) {
      int u = road[0];
      int v = road[1];
      int dist = road[2];
      graph[u].push_back({v, dist});
      graph[v].push_back({u, dist});
    }
    auto bfs = [](const vector<vector<pair<int, int>>> &g, int start_node) {
      int min_dist = INT_MAX;
      queue<int> q;
      unordered_set<int> visited;
      q.push(start_node);
      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (const auto &edge : g[node]) {
          int v = edge.first;
          int dist = edge.second;

          if (visited.find(v) == visited.end()) {
            q.push(v);
            visited.insert(v);
          }
          min_dist = min(min_dist, dist);
        }
      }
      return min_dist;
    };

    return bfs(graph, 1);
  }
};
