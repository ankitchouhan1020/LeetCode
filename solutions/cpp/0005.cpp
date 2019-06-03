class Solution {
 public:
  string longestPalindrome(string s) {
    const int length = s.length() * 2 + 3;

    // Manacher's Algorithm
    string T(length, '#');
    T[0] = '$';
    T[length - 1] = '@';
    for (int i = 2; i < length - 2; i += 2) T[i] = s[i / 2 - 1];

    int center = 1;
    int right = 1;
    vector<int> P(length, 0);

    for (int i = 1; i < length - 1; i++) {
      int mirr = 2 * center - i;
      if (i < right) P[i] = min(P[mirr], right - i);
      while (T[i + P[i] + 1] == T[i - P[i] - 1]) P[i]++;
      if (i + P[i] > right) {
        center = i;
        right = i + P[i];
      }
    }

    // find max and the center;
    int max = 0;
    int c = 0;
    for (int i = 0; i < length; i++)
      if (P[i] > max) {
        max = P[i];
        c = i;
      }

    // omit '#' and get the string desired
    string ans(max, '#');
    int i = 0;
    for (int j = c - max + 1; j < c + max; j += 2) {
      ans[i] = T[j];
      i++;
    }

    return ans;
  }
};