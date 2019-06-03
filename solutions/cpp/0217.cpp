class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;

    for (int num : nums)
      if (!set.insert(num).second) return true;

    return false;
  }
};