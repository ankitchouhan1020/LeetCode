class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)

        cut = [0] * n
        dp = [[False] * n for _ in range(n)]

        for i in range(n):
            min_ = i
            for j in range(i + 1):
                if s[j] == s[i] and (j + 1 > i - 1 or dp[j + 1][i - 1]):
                    dp[j][i] = True
                    min_ = 0 if j == 0 else min(min_, cut[j - 1] + 1)
            cut[i] = min_

        return cut[n - 1]
