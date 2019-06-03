class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        def isMatch(word: str) -> int:
            if word in m:
                return m[word]

            prev = -1
            for c in word:
                index = bisect.bisect_left(dict[c], prev + 1)
                if index == len(dict[c]):
                    m[word] = 0
                    return 0
                prev = dict[c][index]
            m[word] = 1

            return 1

        m = {}
        dict = {chr(i + ord('a')): [] for i in range(26)}

        for i, c in enumerate(S):
            dict[c].append(i)

        return sum(map(isMatch, words))
