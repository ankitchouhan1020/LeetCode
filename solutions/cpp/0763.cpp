class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;

    vector<int> map(26);
    for (int i = 0; i < S.length(); i++) map[S[i] - 'a'] = i;

    int start = 0;
    int end = 0;

    for (int i = 0; i < S.length(); i++) {
      end = max(end, map[S[i] - 'a']);
      if (i == end) {
        ans.push_back(end - start + 1);
        start = end + 1;
      }
    }

    return ans;
  }
};