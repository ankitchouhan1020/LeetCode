class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    priority_queue<ListNode*, vector<ListNode*>, compareListNode> pq;

    for (auto list : lists)
      if (list) pq.push(list);

    while (!pq.empty()) {
      curr->next = pq.top();
      pq.pop();
      curr = curr->next;
      if (curr->next) pq.push(curr->next);
    }

    return dummy.next;
  }

 private:
  struct compareListNode {
    bool operator()(const ListNode* l1, const ListNode* l2) {
      return l1->val > l2->val;
    }
  };
};