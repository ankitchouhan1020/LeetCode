class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    int length = 0;
    for (auto curr = head; curr; curr = curr->next) length++;

    this->head = head;

    return helper(0, length - 1);
  }

 private:
  ListNode* head;

  TreeNode* helper(int l, int r) {
    if (l > r) return NULL;

    int mid = (l + r) >> 1;

    TreeNode* left = helper(l, mid - 1);
    TreeNode* node = new TreeNode(head->val);
    head = head->next;
    node->left = left;
    node->right = helper(mid + 1, r);

    return node;
  }
};