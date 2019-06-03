class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    auto slow = head;
    auto fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }

    if (!fast || !fast->next) return NULL;

    slow = head;

    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};