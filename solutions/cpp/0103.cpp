class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> ans;
    deque<TreeNode*> deque;
    deque.push_back(root);
    bool isLeftToRight = true;

    while (!deque.empty()) {
      vector<int> currLevel;
      for (int i = deque.size(); i > 0; i--) {
        if (isLeftToRight) {
          TreeNode* node = deque.front();
          deque.pop_front();
          currLevel.push_back(node->val);
          if (node->left) deque.push_back(node->left);
          if (node->right) deque.push_back(node->right);
        } else {
          TreeNode* node = deque.back();
          deque.pop_back();
          currLevel.push_back(node->val);
          if (node->right) deque.push_front(node->right);
          if (node->left) deque.push_front(node->left);
        }
      }
      ans.push_back(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
};