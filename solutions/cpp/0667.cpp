class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans(n);

    for (int i = 1; i < n - k; i++) ans[i - 1] = i;

    int j = n - k - 1;

    for (int i = 0; i <= k; i++)
      ans[j++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);

    return ans;
  }
};