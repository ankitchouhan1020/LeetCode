class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    int ans = nums.size();
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    unordered_map<int, int> map;
    int degree = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (!left.count(nums[i])) left[nums[i]] = i;
      right[nums[i]] = i;
      map[nums[i]]++;
    }

    for (auto& [_, value] : map) degree = max(degree, value);

    for (auto& [key, value] : map)
      if (value == degree) ans = min(ans, right[key] - left[key] + 1);

    return ans;
  }
};