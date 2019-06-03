class Solution {
 public:
  int rob(TreeNode* root) {
    vector<int> ans = helper(root);

    return max(ans[0], ans[1]);
  }

  vector<int> helper(TreeNode* root) {
    if (!root) return {0, 0};

    vector<int> left = helper(root->left);
    vector<int> right = helper(root->right);

    return {max(left[0], left[1]) + max(right[0], right[1]),
            root->val + left[0] + right[0]};
  }
};