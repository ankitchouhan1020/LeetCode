class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& G) {
    int ans = 0;
    unordered_set<int> g(G.begin(), G.end());

    while (head) {
      if (g.count(head->val) && (!head->next || !g.count(head->next->val)))
        ans++;
      head = head->next;
    }

    return ans;
  }
};