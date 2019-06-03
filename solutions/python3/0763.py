class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        ans = []

        dict = {c: i for i, c in enumerate(S)}

        start = 0
        end = 0

        for i, c in enumerate(S):
            end = max(end, dict[c])
            if i == end:
                ans.append(end - start + 1)
                start = end + 1

        return ans
