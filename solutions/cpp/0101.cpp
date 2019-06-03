class Solution {
 public:
  bool isSymmetric(TreeNode* root) { return helper(root, root); }

 private:
  bool helper(TreeNode* p, TreeNode* q) {
    if (!p || !q) return p == q;

    return p->val == q->val &&
           helper(p->left, q->right) &&
           helper(p->right, q->left);
  }
};