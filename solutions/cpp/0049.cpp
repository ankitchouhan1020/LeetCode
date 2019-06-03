class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;

    for (string& str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      map[s].push_back(str);
    }

    for (auto& [key, value] : map) {
      vector<string> s = value;
      sort(s.begin(), s.end());
      ans.push_back(s);
    }

    return ans;
  }
};