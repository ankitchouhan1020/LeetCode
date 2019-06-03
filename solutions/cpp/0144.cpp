class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;

    stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
      TreeNode* node = stack.top();
      ans.push_back(node->val);
      stack.pop();
      if (node->right) stack.push(node->right);
      if (node->left) stack.push(node->left);
    }

    return ans;
  }
};