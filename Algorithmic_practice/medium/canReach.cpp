#include <ios>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
  bool dfs(int node_index, set<int> &visited, int size_n,
           const vector<int> &arr) {
    if (0 > node_index or node_index > size_n or visited.count(node_index)) {
      return false;
    } else if (arr[node_index] == 0) {
      return true;
    } else {
      visited.insert(node_index);
      int right_node = node_index + arr[node_index];
      int left_node = node_index - arr[node_index];
      for (int i : {right_node, left_node}) {
        if (dfs(i, visited, size_n, arr)) {
          return true;
        }
      }
    }
    return false;
  }

public:
  bool canReach(vector<int> &arr, int start) {
    set<int> visited;
    int n = static_cast<int>(arr.size()) - 1;
    return dfs(start, visited, n, arr);
  }
};

int main() {
  Solution obj;
  vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
  int start = 5;
  cout << boolalpha << obj.canReach(arr, start);
}
