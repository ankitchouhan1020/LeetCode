class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN;
    int sum = 0;

    for (int num : nums) {
      sum += num;
      if (sum > ans) ans = sum;
      if (sum < 0) sum = 0;
    }

    return ans;
  }
};