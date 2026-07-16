#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  unordered_map<int, vector<int>> graph;
  unordered_map<int, int> depth;
  unordered_map<int, int> parents;
  vector<vector<int>> up;

  long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000000007;
    base %= mod;
    while (exp > 0) {
      if (exp % 2 == 1)
        res = (res * base) % mod;
      base = (base * base) % mod;
      exp /= 2;
    }
    return res;
  }

  void dfs(int node, int parent_node, int distance) {
    depth[node] = distance;
    parents[node] = parent_node;
    for (int neighbor : graph[node]) {
      if (neighbor != parent_node) {
        dfs(neighbor, node, distance + 1);
      }
    }
  }

public:
  vector<int> assignEdgeWeights(vector<vector<int>> &edges,
                                vector<vector<int>> &queries) {
    graph.clear();
    depth.clear();
    parents.clear();

    for (const auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    int n = edges.size() + 1;
    up.assign(n + 1, vector<int>(18, 0));

    dfs(1, 0, 0);

    for (int i = 1; i <= n; ++i) {
      if (parents.count(i)) {
        up[i][0] = parents[i];
      } else {
        up[i][0] = 0;
      }
    }

    for (int j = 1; j < 18; ++j) {
      for (int i = 1; i <= n; ++i) {
        int half = up[i][j - 1];
        if (half != 0) {
          up[i][j] = up[half][j - 1];
        }
      }
    }

    vector<int> ans;
    long long mod = 1000000007;

    for (const auto &query : queries) {
      int u = query[0];
      int v = query[1];
      int s_u = u;
      int s_v = v;

      if (depth[u] < depth[v]) {
        swap(u, v);
      }
      int diff = depth[u] - depth[v];
      for (int j = 17; j >= 0; --j) {
        int jump_size = 1 << j;
        if (diff >= jump_size) {
          u = up[u][j];
          diff -= jump_size;
        }
      }

      if (u == v) {
        int lca = u;
        int L = depth[s_u] + depth[s_v] - 2 * depth[lca];
        if (L == 0) {
          ans.push_back(0);
        } else {
          ans.push_back(power(2, L - 1));
        }
        continue;
      }

      for (int j = 17; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
          u = up[u][j];
          v = up[v][j];
        }
      }

      int lca = up[u][0];
      int L = depth[s_u] + depth[s_v] - 2 * depth[lca];
      if (L == 0) {
        ans.push_back(0);
      } else {
        ans.push_back(power(2, L - 1));
      }
    }

    return ans;
  }
};
