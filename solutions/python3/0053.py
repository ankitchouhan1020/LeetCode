class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = float('-inf')
        sum = 0

        for num in nums:
            sum += num
            if sum > ans:
                ans = sum
            if sum < 0:
                sum = 0

        return ans
