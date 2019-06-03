class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stack;
    TreeNode* curr = root;

    while (curr || !stack.empty()) {
      while (curr) {
        stack.push(curr);
        curr = curr->left;
      }
      curr = stack.top();
      stack.pop();
      ans.push_back(curr->val);
      curr = curr->right;
    }

    return ans;
  }
};