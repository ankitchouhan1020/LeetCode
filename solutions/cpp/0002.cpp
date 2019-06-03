class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;

    while (carry || l1 || l2) {
      carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      curr->next = new ListNode(carry % 10);
      curr = curr->next;
      carry /= 10;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    return dummy.next;
  }
};