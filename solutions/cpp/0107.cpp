class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> ans;

    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
      vector<int> currLevel;
      for (int i = queue.size(); i > 0; i--) {
        TreeNode* node = queue.front();
        queue.pop();
        currLevel.push_back(node->val);
        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }
      ans.insert(ans.begin(), currLevel);
    }

    return ans;
  }
};