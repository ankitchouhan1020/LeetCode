class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    if (s.length() == 1) return 1;

    int dp1 = 1;
    int dp2 = 1;

    for (int i = 1; i < s.length(); i++) {
      int dp = 0;
      if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
      if (isValid(s[i])) dp += dp1;
      if (isValid(s[i - 1], s[i])) dp += dp2;
      dp2 = dp1;
      dp1 = dp;
    }

    return dp1;
  }

 private:
  bool isValid(char c) { return c != '0'; }
  bool isValid(char c1, char c2) {
    return c1 == '1' || (c1 == '2' && c2 <= '6');
  }
};