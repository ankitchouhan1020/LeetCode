class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;

    int ans = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) map[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++)
      if (map.count(nums[i] + k) && map[nums[i] + k] != i) {
        ans++;
        map.erase(nums[i] + k);
      }

    return ans;
  }
};