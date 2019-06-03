class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m = len(s1)
        n = len(s2)

        map1 = [0] * 26
        map2 = [0] * 26

        for c in s1:
            map1[ord(c) - ord('a')] += 1

        for i in range(n):
            if i >= m:
                map2[ord(s2[i - m]) - ord('a')] -= 1
            map2[ord(s2[i]) - ord('a')] += 1
            if map1 == map2:
                return True

        return False
