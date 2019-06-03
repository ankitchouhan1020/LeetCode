class Solution {
 public:
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    vector<int> stack;

    for (auto curr = head; curr; curr = curr->next) {
      while (stack.size() && ans[stack.back()] < curr->val) {
        ans[stack.back()] = curr->val;
        stack.pop_back();
      }
      stack.push_back(ans.size());
      ans.push_back(curr->val);
    }

    for (int i : stack) ans[i] = 0;

    return ans;
  }
};