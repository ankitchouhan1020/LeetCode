class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* l1 = head;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = NULL;

    ListNode* l2 = reverse(slow);
    merge(l1, l2);
  }

 private:
  ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
      auto next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }

  void merge(ListNode* l1, ListNode* l2) {
    while (l2) {
      auto next = l1->next;
      l1->next = l2;
      l1 = l2;
      l2 = next;
    }
  }
};