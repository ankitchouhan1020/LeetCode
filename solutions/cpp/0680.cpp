class Solution {
 public:
  bool validPalindrome(string s) {
    const int n = s.length();

    for (int i = 0; i < n / 2; i++)
      if (s[i] != s[n - 1 - i])
        return validPalindrome(s, i + 1, n - 1 - i) ||
               validPalindrome(s, i, n - 2 - i);

    return true;
  }

 private:
  bool validPalindrome(string& s, int l, int r) {
    for (int i = l; i <= l + (r - l) / 2; i++)
      if (s[i] != s[r - i + l]) return false;

    return true;
  }
};