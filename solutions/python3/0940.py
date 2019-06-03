class Solution:
    def distinctSubseqII(self, S: str) -> int:
        dict = [0] * 26

        for c in S:
            dict[ord(c) - ord('a')] = (sum(dict) + 1) % int(1e9+7)

        return sum(dict) % int(1e9+7)
