#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions) {
    std::unordered_map<int, TreeNode *> node;
    std::unordered_set<int> children;
    for (std::vector<int> desc : descriptions) {
      int parent = desc[0], child = desc[1], isleft = desc[2];
      if (!node.contains(parent)) {
        node[parent] = new TreeNode(parent);
      }
      children.insert(child);
      if (!node.contains(child)) {
        node[child] = new TreeNode(child);
      }
      if (isleft == 1)
        node[parent]->left = node[child];
      else
        node[parent]->right = node[child];
    }
    for (const auto &val : node) {
      if (!children.contains(val.first)) {
        return val.second;
      }
    }
    return nullptr;
  }
};
