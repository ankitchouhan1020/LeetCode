class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        max_ = ans
        min_ = ans

        for i in range(1, len(nums)):
            if nums[i] < 0:
                max_, min_ = min_, max_
            max_ = max(nums[i], max_ * nums[i])
            min_ = min(nums[i], min_ * nums[i])
            ans = max(ans, max_)

        return ans
