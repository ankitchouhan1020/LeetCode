class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    string ans;

    vector<int> map(26);
    for (char c : licensePlate)
      if (isalpha(c)) map[tolower(c) - 'a']++;

    int min = INT_MAX;

    for (string& word : words) {
      if (word.length() >= min) continue;
      if (!isMatch(word, map)) continue;
      min = word.length();
      ans = word;
    }

    return ans;
  }

 private:
  bool isMatch(string& word, vector<int>& map) {
    vector<int> wordMap(26);
    for (char c : word) wordMap[c - 'a']++;

    for (int i = 0; i < 26; i++)
      if (wordMap[i] < map[i]) return false;

    return true;
  }
};