#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  pair<int, int> bfs(int node, const unordered_map<int, vector<int>> &graph,
                     vector<bool> &visited) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int comp_nodes = 0;
    int total_degree = 0;
    while (!q.empty()) {
      int val = q.front();
      q.pop();
      comp_nodes++;
      if (graph.find(val) != graph.end()) {
        total_degree += graph.at(val).size();
        for (int v : graph.at(val)) {
          if (!visited[v]) {
            visited[v] = true;
            q.push(v);
          }
        }
      }
    }

    return {comp_nodes, total_degree};
  }

public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> graph;
    for (const auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    vector<bool> visited(n, false);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        pair<int, int> result = bfs(i, graph, visited);
        int Vc = result.first;
        int total_degree = result.second;
        int Ec = total_degree / 2;
        if (Ec == (Vc * (Vc - 1)) / 2) {
          res++;
        }
      }
    }

    return res;
  }
};
