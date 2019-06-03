class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;

    stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
      TreeNode* node = stack.top();
      ans.push_back(node->val);
      stack.pop();
      if (node->left) stack.push(node->left);
      if (node->right) stack.push(node->right);
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};