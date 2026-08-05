#include <queue>

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
  bool isSymmetric_dfs(TreeNode *root) {
    if (!root)
      return true;
    return dfs(root->left, root->right);
  }

private:
  bool dfs(TreeNode *left_node, TreeNode *right_node) {
    if (!left_node && !right_node)
      return true;
    if (!left_node || !right_node)
      return false;
    if (left_node->val != right_node->val)
      return false;
    return dfs(left_node->left, right_node->right) &&
           dfs(left_node->right, right_node->left);
  }
  bool isSymmetric_bfs(TreeNode *root) {
    if (!root)
      return true;
    std::queue<std::pair<TreeNode *, TreeNode *>> q;
    q.push({root->left, root->right});
    while (!q.empty()) {
      auto [left, right] = q.front();
      q.pop();
      if (!left && !right)
        continue;
      if (!left || !right)
        return false;
      if (left->val != right->val)
        return false;
      q.push({left->left, right->right});
      q.push({left->right, right->left});
    }
    return true;
  }
};
