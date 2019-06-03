class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        n = len(A)

        ans = 0

        dict = {a: i for i, a in enumerate(A)}

        dp = [[2] * n for _ in range(n)]

        for j in range(n):
            for k in range(j + 1, n):
                if A[k] - A[j] < A[j] and A[k] - A[j] in dict:
                    i = dict[A[k] - A[j]]
                    dp[j][k] = dp[i][j] + 1
                    ans = max(ans, dp[j][k])

        return ans
