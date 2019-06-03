class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dict_s = collections.defaultdict(int)
        dict_t = collections.defaultdict(int)

        for i in range(len(s)):
            if dict_s[s[i]] != dict_t[t[i]]:
                return False
            dict_s[s[i]] = i + 1
            dict_t[t[i]] = i + 1

        return True
