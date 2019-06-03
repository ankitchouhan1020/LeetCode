class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;

    unordered_map<int, int> map;
    for (int num : nums) map[num]++;

    for (auto& [key, value] : map)
      if (value > nums.size() / 3) ans.push_back(key);

    return ans;
  }
};