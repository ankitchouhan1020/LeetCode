class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> ans(k, NULL);
    int length = 0;
    for (auto curr = root; curr; curr = curr->next) length++;
    int l = length / k;
    int r = length % k;

    ListNode* head = root;
    ListNode* prev = NULL;

    for (int i = 0; i < k; i++, r--) {
      ans[i] = head;
      for (int j = 0; j < l + (r > 0); j++) {
        prev = head;
        head = head->next;
      }
      if (prev) prev->next = NULL;
    }

    return ans;
  }
};