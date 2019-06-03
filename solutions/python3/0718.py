class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m = len(A)
        n = len(B)

        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if A[i] == B[j]:
                    dp[i][j] = dp[i + 1][j + 1] + 1

        return max(max(row) for row in dp)
