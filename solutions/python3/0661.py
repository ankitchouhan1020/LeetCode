class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        m = len(M)
        n = len(M[0])

        ans = [[0 for j in range(n)] for i in range(m)]

        for i in range(m):
            for j in range(n):
                ans[i][j] = self.helper(M, i, j)

        return ans

    def helper(self, M: List[List[int]], x: int, y: int) -> int:
        sum = 0
        count = 0

        for i in range(-1, 2):
            for j in range(-1, 2):
                if x + i < 0 or x + i >= len(M) or \
                   y + j < 0 or y + j >= len(M[0]):
                    continue
                count += 1
                sum += M[x + i][y + j]

        return sum // count
