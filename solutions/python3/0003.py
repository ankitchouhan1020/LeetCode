class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        dict = {}

        j = 0
        for i in range(len(s)):
            c = s[i]
            if c in dict:
                j = max(j, dict[c])
            ans = max(ans, i - j + 1)
            dict[c] = i + 1

        return ans
