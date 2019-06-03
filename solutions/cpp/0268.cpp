class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    const int n = nums.size();

    int gaussSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int num : nums) actualSum += num;

    return gaussSum - actualSum;
  }
};