class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();

    vector<int> ans(n);
    ans[0] = 1;
    int r = 1;

    for (int i = 1; i < n; i++) ans[i] = nums[i - 1] * ans[i - 1];

    for (int i = n - 1; i >= 0; i--) {
      ans[i] *= r;
      r *= nums[i];
    }

    return ans;
  }
};