class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    const int n = nums.size();

    unordered_map<int, int> map;

    for (int num : nums)
      if (++map[num] > n / 2) return num;

    return -1;
  }
};