class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    if (nums.empty()) return 0;

    int ans = 0;
    int sum = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i] ? 1 : -1;
      if (sum == 0) {
        ans = i + 1;
      } else if (map.count(sum)) {
        ans = max(ans, i - map[sum]);
      } else {
        map[sum] = i;
      }
    }

    return ans;
  }
};