class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() < 2) return nums[0];

    const int n = nums.size();

    return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
  }

 private:
  int rob(vector<int>& nums, int l, int r) {
    int dp1 = 0;
    int dp2 = 0;

    for (int i = l; i <= r; i++) {
      int temp = dp1;
      dp1 = max(dp1, dp2 + nums[i]);
      dp2 = temp;
    }

    return dp1;
  }
};