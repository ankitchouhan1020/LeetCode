class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]

        ans = ""
        min_ = len(strs[0])
        isMatch = True

        for i in range(1, len(strs)):
            min_ = min(min_, len(strs[i]))

        for i in range(min_):
            c = strs[0][i]
            for j in range(1, len(strs)):
                if c != strs[j][i]:
                    isMatch = False
                    break
            if not isMatch:
                break
            ans += c

        return ans
