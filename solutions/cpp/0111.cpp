class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    int ans = 0;

    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
      ans++;
      for (int i = queue.size(); i > 0; i--) {
        TreeNode* node = queue.front();
        queue.pop();
        if (!node->left && !node->right) return ans;
        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }
    }

    return -1;
  }
};