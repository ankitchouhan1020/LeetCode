class Solution {
 public:
  int rob(vector<int>& nums) {
    int dp1 = 0;
    int dp2 = 0;

    for (int num : nums) {
      int temp = dp1;
      dp1 = max(dp1, dp2 + num);
      dp2 = temp;
    }

    return dp1;
  }
};