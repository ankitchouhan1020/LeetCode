class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode dummy(0);
    dummy.next = head;
    int length = 0;
    for (auto curr = head; curr; curr = curr->next) length++;

    auto prev = &dummy;
    auto curr = head;

    for (int i = 0; i < length / 2; i++) {
      auto next = curr->next;
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
      prev = curr;
      curr = curr->next;
    }

    return dummy.next;
  }
};