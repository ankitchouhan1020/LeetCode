class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    unordered_map<char, int> map;

    for (int i = 0; i < s.length(); i++) map[s[i]] = i;

    for (int i = 0; i < s.length(); i++)
      for (char d = '9'; d > s[i]; d--)
        if (map[d] > i) {
          char temp = s[i];
          s[i] = s[map[d]];
          s[map[d]] = temp;
          return stoi(s);
        }

    return num;
  }
};