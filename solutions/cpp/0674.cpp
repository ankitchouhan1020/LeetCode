class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int ans = 0;
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i - 1] >= nums[i]) j = i;
      ans = max(ans, i - j + 1);
    }

    return ans;
  }
};