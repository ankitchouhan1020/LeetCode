class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        dict = [0] * 26
        for task in tasks:
            dict[ord(task) - ord('A')] += 1
        dict.sort()

        i = 25

        while i >= 0 and dict[i] == dict[25]:
            i -= 1

        return max(len(tasks), (dict[25] - 1) * (n + 1) + 25 - i)
