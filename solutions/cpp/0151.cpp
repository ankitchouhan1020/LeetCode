class Solution {
 public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    reverseWords(s, 0, 0);

    return cleanSpaces(s, 0, 0);
  }

 private:
  void reverseWords(string& s, int i, int j) {
    while (i < s.length()) {
      while (i < j || i < s.length() && s[i] == ' ') i++;
      while (j < i || j < s.length() && s[j] != ' ') j++;
      reverse(s.begin() + i, s.begin() + j);
    }
  }

  string cleanSpaces(string& s, int i, int j) {
    while (j < s.length()) {
      while (j < s.length() && s[j] == ' ') j++;
      while (j < s.length() && s[j] != ' ') s[i++] = s[j++];
      while (j < s.length() && s[j] == ' ') j++;
      if (j < s.length()) s[i++] = ' ';
    }

    return s.substr(0, i);
  }
};