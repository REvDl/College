#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int shortestPath(int n, vector<vector<int>> &edges, string labels, int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
    }

    vector<unordered_map<int, int>> distances(n);
    distances[0][1] = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
      auto current = pq.top();
      pq.pop();

      int current_dist = current[0];
      int u = current[1];
      int run = current[2];

      if (distances[u].find(run) == distances[u].end() ||
          current_dist > distances[u][run]) {
        continue;
      }

      for (const auto &neighbor : graph[u]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        int distance = current_dist + weight;
        int new_run = (labels[u] == labels[v]) ? run + 1 : 1;

        if (new_run > k) {
          continue;
        }

        if (distances[v].find(new_run) == distances[v].end() ||
            distance < distances[v][new_run]) {
          distances[v][new_run] = distance;
          pq.push({distance, v, new_run});
        }
      }
    }

    if (distances[n - 1].empty()) {
      return -1;
    }

    int min_dist = 2e9;
    for (const auto &pair : distances[n - 1]) {
      min_dist = min(min_dist, pair.second);
    }

    return min_dist;
  }
};
