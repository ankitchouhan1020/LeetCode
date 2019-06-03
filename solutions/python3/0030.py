class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []

        m = len(s)
        n = len(words[0])

        ans = []

        dict = collections.Counter(words)

        for i in range(n):
            index = i
            count = 0
            tempDict = collections.defaultdict(int)
            for j in range(i, m - n + 1, n):
                str = s[j: j + n]
                if str in dict.keys():
                    tempDict[str] += 1
                    count += 1
                    while tempDict[str] > dict[str]:
                        tempDict[s[index: index + n]] -= 1
                        count -= 1
                        index += n
                    if count == len(words):
                        ans.append(index)
                        tempDict[s[index: index + n]] -= 1
                        count -= 1
                        index += n
                else:
                    tempDict.clear()
                    count = 0
                    index = j + n

        return ans
