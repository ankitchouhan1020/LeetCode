class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        sum_ = sum(nums[:k])
        ans = sum_

        for i in range(k, len(nums)):
            sum_ += nums[i] - nums[i - k]
            ans = max(ans, sum_)

        return ans / k
