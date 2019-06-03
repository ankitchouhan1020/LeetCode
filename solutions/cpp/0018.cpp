class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return {};

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; i++)
      if (i == 0 || nums[i] != nums[i - 1])
        for (int j = i + 1; j < nums.size() - 2; j++)
          if (j == i + 1 || nums[j] != nums[j - 1]) {
            int l = j + 1;
            int r = nums.size() - 1;
            int newTarget = target - nums[i] - nums[j];
            while (l < r) {
              if (nums[l] + nums[r] == newTarget) {
                ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
              } else if (nums[l] + nums[r] < newTarget) {
                l++;
              } else {
                r--;
              }
            }
          }

    return ans;
  }
};