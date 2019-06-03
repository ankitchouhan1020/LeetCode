class Solution {
 public:
  Solution(ListNode* head) {
    privateHead = head;
    for (auto curr = head; curr; curr = curr->next) length++;
  }

  int getRandom() {
    int n = rand() % length;
    ListNode* curr = privateHead;
    while (n-- > 0) curr = curr->next;
    return curr->val;
  }

 private:
  ListNode* privateHead;
  int length = 0;
};