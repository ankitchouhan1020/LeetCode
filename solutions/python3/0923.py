class Solution:
    def threeSumMulti(self, A: List[int], target: int) -> int:
        ans = 0

        dict = collections.Counter(A)

        for i, x in dict.items():
            for j, y in dict.items():
                k = target - i - j
                if k not in dict:
                    continue
                if i == j and j == k:
                    ans += x * (x - 1) * (x - 2) // 6
                elif i == j and j != k:
                    ans += x * (x - 1) // 2 * dict[k]
                elif i < j and j < k:
                    ans += x * y * dict[k]

        return ans % int(1e9 + 7)
