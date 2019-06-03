class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries or duration == 0:
            return 0

        ans = 0

        for i in range(len(timeSeries) - 1):
            ans += min(timeSeries[i + 1] - timeSeries[i], duration)

        return ans + duration
