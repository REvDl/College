#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using Defaultdict = unordered_map<int, vector<int>>;

class Solution {
private:
  int bfs(vector<int> &arr, int node, int size, Defaultdict &steps_map) {
    deque<pair<int, int>> queue = {{0, 0}};
    unordered_set<int> visited;
    visited.insert(0);
    visited.insert(0);
    while (!queue.empty()) {
      vector<int> next_steps = {};
      pair<int, int> current = queue.front();
      queue.pop_front();
      int index = current.first, steps = current.second;
      if (index == size) {
        return steps;
      }
      if (index + 1 <= size)
        next_steps.push_back(index + 1);
      if (index - 1 >= 0)
        next_steps.push_back(index - 1);
      for (const auto &i : steps_map[arr[index]]) {
        if (i != index) {
          next_steps.push_back(i);
        }
      }
      steps_map[arr[index]].clear();
      for (const auto &neigh : next_steps) {
        if (visited.find(neigh) == visited.end()) {
          visited.insert(neigh);
          queue.push_back({neigh, steps + 1});
        }
      }
    }
    return -1;
  }

public:
  int minJumps(vector<int> &arr) {
    int n = static_cast<int>(arr.size() - 1);
    Defaultdict steps_map;
    for (int index = 0; index <= n; ++index) {
      int val = arr[index];
      steps_map[val].push_back(index);
    }
    return bfs(arr, 0, n, steps_map);
  }
};
