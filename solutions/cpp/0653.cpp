class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;

    inorder(root, nums);

    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int sum = nums[l] + nums[r];
      if (sum == k) return true;
      if (sum < k)
        l++;
      else
        r--;
    }

    return false;
  }

  void inorder(TreeNode* root, vector<int>& nums) {
    if (!root) return;

    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }
};