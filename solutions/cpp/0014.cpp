class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];

    string ans;
    int min = strs[0].length();
    bool isMatch = true;

    for (int i = 1; i < strs.size(); i++)
      min = std::min(min, (int)strs[i].length());

    for (int i = 0; i < min; i++) {
      char c = strs[0][i];
      for (int j = 1; j < strs.size(); j++)
        if (c != strs[j][i]) {
          isMatch = false;
          break;
        }
      if (!isMatch) break;
      ans += c;
    }

    return ans;
  }
};