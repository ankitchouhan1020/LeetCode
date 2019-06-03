class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int ans = INT_MAX;
    int sum = 0;
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      while (sum >= s) {
        ans = min(ans, i - j + 1);
        sum -= nums[j++];
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};