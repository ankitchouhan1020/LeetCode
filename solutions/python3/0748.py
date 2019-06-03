class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        def isMatch(word: str) -> bool:
            wordDict = collections.Counter(word)

            for i in string.ascii_lowercase:
                if wordDict[i] < dict[i]:
                    return False

            return True

        dict = {chr(i + ord('a')): 0 for i in range(26)}
        for c in licensePlate:
            if c.isalpha():
                dict[c.lower()] += 1

        min = float('inf')

        for word in words:
            if len(word) >= min:
                continue
            if not isMatch(word):
                continue
            min = len(word)
            ans = word

        return ans
