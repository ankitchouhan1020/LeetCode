class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ans = 0;

    for (int num : nums)
      if (num != INT_MAX) {
        int start = num;
        int count = 0;
        while (nums[start] != INT_MAX) {
          int temp = start;
          start = nums[start];
          nums[temp] = INT_MAX;
          count++;
        }
        ans = max(ans, count);
      }

    return ans;
  }
};