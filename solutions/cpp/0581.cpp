class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int min = INT_MAX;
    int max = INT_MIN;
    bool flag = false;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) flag = true;
      if (flag) min = std::min(min, nums[i]);
    }

    flag = false;

    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] > nums[i + 1]) flag = true;
      if (flag) max = std::max(max, nums[i]);
    }

    int l;
    int r;

    for (l = 0; l < nums.size(); l++)
      if (nums[l] > min) break;

    for (r = nums.size() - 1; r >= 0; r--)
      if (nums[r] < max) break;

    return r - l <= 0 ? 0 : r - l + 1;
  }
};