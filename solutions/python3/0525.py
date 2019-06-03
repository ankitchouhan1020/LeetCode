class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if not nums:
            return 0

        ans = 0
        sum = 0
        dict = {}

        for i in range(len(nums)):
            sum += 1 if nums[i] else -1
            if sum == 0:
                ans = i + 1
            elif sum in dict:
                ans = max(ans, i - dict[sum])
            else:
                dict[sum] = i

        return ans
