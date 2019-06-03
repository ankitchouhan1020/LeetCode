class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int ans = 0;

    sort(nums.begin(), nums.end());

    for (int k = nums.size() - 1; k > 1; k--)
      for (int i = 0, j = k - 1; i < j;) {
        if (nums[i] + nums[j] > nums[k]) {
          ans += j - i;
          j--;
        } else {
          i++;
        }
      }

    return ans;
  }
};
