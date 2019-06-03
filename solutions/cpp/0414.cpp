class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    set<int> set;

    for (int num : nums) {
      set.insert(num);
      if (set.size() > 3) set.erase(set.begin());
    }

    return set.size() == 3 ? *set.begin() : *set.rbegin();
  }
};