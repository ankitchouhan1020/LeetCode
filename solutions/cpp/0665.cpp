class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int count = 0;
    int j;

    for (int i = 0; i < nums.size() - 1; i++)
      if (nums[i] > nums[i + 1]) {
        count++;
        if (count > 1) return false;
        j = i;
      }

    return (count == 0 || j == 0 || j == nums.size() - 2) ||
           nums[j - 1] <= nums[j + 1] || nums[j] <= nums[j + 2];
  }
};