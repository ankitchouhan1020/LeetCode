class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    const int m = s1.length();
    const int n = s2.length();

    vector<int> map1(26);
    vector<int> map2(26);

    for (char c : s1) map1[c - 'a']++;

    for (int i = 0; i < n; i++) {
      if (i >= m) map2[s2[i - m] - 'a']--;
      map2[s2[i] - 'a']++;
      if (map1 == map2) return true;
    }

    return false;
  }
};