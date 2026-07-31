#include <string>
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
private:
  std::vector<std::string> paths_tree;

  void dfs(TreeNode *node, std::string path_tree) {
    if (!node)
      return;

    if (path_tree.empty()) {
      path_tree += std::to_string(node->val);
    } else {
      path_tree += "->" + std::to_string(node->val);
    }

    if (node->left) {
      dfs(node->left, path_tree);
    }
    if (node->right) {
      dfs(node->right, path_tree);
    }
    if (!node->left && !node->right) {
      paths_tree.push_back(path_tree);
    }
  }

public:
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    paths_tree.clear();
    if (root) {
      dfs(root, "");
    }
    return paths_tree;
  }
};
