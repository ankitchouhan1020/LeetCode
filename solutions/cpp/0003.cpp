class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<char, int> map;

    int j = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (map.count(c)) j = max(j, map[c]);
      ans = max(ans, i - j + 1);
      map[c] = i + 1;
    }

    return ans;
  }
};