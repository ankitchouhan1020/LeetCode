class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        dict = collections.Counter(t)

        l = 0
        r = 0
        bestLeft = 0
        bestRight = 0
        required = len(dict)
        windowLength = len(s) + 1

        for r in range(len(s)):
            if s[r] in dict:
                dict[s[r]] -= 1
                if dict[s[r]] == 0:
                    required -= 1

            while required == 0 and l <= r:
                if r - l + 1 < windowLength:
                    windowLength = r - l + 1
                    bestLeft = l
                    bestRight = r

                if s[l] in dict:
                    dict[s[l]] += 1
                    if dict[s[l]] > 0:
                        required += 1

                l += 1

        return "" if windowLength == len(s) + 1 else s[bestLeft: bestRight + 1]
