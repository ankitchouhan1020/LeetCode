class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty()) return 0;

    long dp1 = count(s[0]);
    long dp2 = 1;

    for (int i = 1; i < s.length(); i++) {
      long dp = count(s[i]) * dp1 + count(s[i - 1], s[i]) * dp2;
      dp %= int(1e9 + 7);
      dp2 = dp1;
      dp1 = dp;
    }

    return dp1;
  }

 private:
  int count(char c) {
    if (c == '*') return 9;
    return c != '0';
  }

  int count(char c1, char c2) {
    if (c1 == '*' && c2 == '*') return 15;
    if (c1 == '*') return (c2 >= '0' && c2 <= '6') ? 2 : 1;
    if (c2 == '*') {
      if (c1 == '1') return 9;
      if (c1 == '2') return 6;
      return 0;
    }
    return c1 == '1' || (c1 == '2' && c2 <= '6');
  }
};