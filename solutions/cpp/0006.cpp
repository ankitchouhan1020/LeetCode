class Solution {
 public:
  string convert(string s, int numRows) {
    string ans(s);
    vector<vector<char>> rows(numRows);
    int k = 0;
    int direction = (numRows == 1) - 1;

    for (char c : s) {
      rows[k].push_back(c);
      if (k == 0 || k == numRows - 1) direction *= -1;
      k += direction;
    }

    k = 0;
    for (int i = 0; i < numRows; i++)
      for (int j = 0; j < rows[i].size(); j++) ans[k++] = rows[i][j];

    return ans;
  }
};