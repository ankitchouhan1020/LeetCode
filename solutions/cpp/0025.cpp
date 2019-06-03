class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode dummy(0);
    dummy.next = head;
    int length = 0;
    for (auto curr = head; curr; curr = curr->next) length++;

    auto prev = &dummy;
    auto curr = head;

    for (int i = 0; i < length / k; i++) {
      for (int j = 0; j < k - 1; j++) {
        auto next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
      }
      prev = curr;
      curr = curr->next;
    }

    return dummy.next;
  }
};