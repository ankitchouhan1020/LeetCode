class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0

        ans = 0
        prod = 1
        j = 0

        for i in range(len(nums)):
            prod *= nums[i]
            while prod >= k:
                prod /= nums[j]
                j += 1
            ans += i - j + 1

        return ans
