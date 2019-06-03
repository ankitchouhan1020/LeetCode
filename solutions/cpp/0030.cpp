class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return {};

    const int m = s.length();
    const int n = words[0].length();

    vector<int> ans;

    unordered_map<string, int> map;
    for (string& word : words) map[word]++;

    for (int i = 0; i < n; i++) {
      int index = i;
      int count = 0;
      unordered_map<string, int> tempMap;
      for (int j = i; j <= m - n; j += n) {
        string str = s.substr(j, n);
        if (map.count(str)) {
          tempMap[str]++;
          count++;
          while (tempMap[str] > map[str]) {
            tempMap[s.substr(index, n)]--;
            count--;
            index += n;
          }
          if (count == words.size()) {
            ans.push_back(index);
            tempMap[s.substr(index, n)]--;
            count--;
            index += n;
          }
        } else {
          tempMap.clear();
          count = 0;
          index = j + n;
        }
      }
    }

    return ans;
  }
};