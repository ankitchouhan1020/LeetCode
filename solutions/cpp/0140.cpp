class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    return wordBreak(s, set);
  }

 private:
  unordered_map<string, vector<string>> map;

  vector<string>& wordBreak(string& s, unordered_set<string>& set) {
    if (map.count(s)) return map[s];

    vector<string> ans;

    if (set.count(s)) ans.push_back(s);

    for (int i = 1; i < s.length(); i++) {
      string right = s.substr(i);
      if (set.count(right)) {
        string left = s.substr(0, i);
        vector<string> leftAns = append(wordBreak(left, set), right);
        ans.insert(ans.end(), leftAns.begin(), leftAns.end());
      }
    }

    return map[s] = ans;
  }

  vector<string> append(vector<string> prefixes, string& word) {
    for (string& prefix : prefixes) prefix += " " + word;
    return prefixes;
  }
};