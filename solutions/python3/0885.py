class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        ans = [[r0, c0]]
        x = 0
        y = 1
        i = 0

        while len(ans) < R * C:
            for j in range(i // 2 + 1):
                r0 += x
                c0 += y
                if 0 <= r0 < R and 0 <= c0 < C:
                    ans.append([r0, c0])
            x, y = y, -x
            i += 1

        return ans
