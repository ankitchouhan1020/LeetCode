class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int length = 0;
    for (auto curr = head; curr; curr = curr->next) length++;

    k %= length;
    if (k == 0) return head;

    auto slow = head;
    auto fast = head;

    while (k--) fast = fast->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    auto ans = slow->next;
    slow->next = NULL;
    fast->next = head;

    return ans;
  }
};