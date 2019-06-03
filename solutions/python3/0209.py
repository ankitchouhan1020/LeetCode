class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        ans = float('inf')
        sum = 0
        j = 0

        for i in range(len(nums)):
            sum += nums[i]
            while sum >= s:
                ans = min(ans, i - j + 1)
                sum -= nums[j]
                j += 1

        return 0 if ans == float('inf') else ans
