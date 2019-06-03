class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(0);
    ListNode* curr = head;

    while (curr) {
      auto prev = &dummy;
      while (prev->next && prev->next->val < curr->val) prev = prev->next;
      auto next = curr->next;
      curr->next = prev->next;
      prev->next = curr;
      curr = next;
    }

    return dummy.next;
  }
};