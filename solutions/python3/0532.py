class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0

        ans = 0
        dict = {}

        for i in range(len(nums)):
            dict[nums[i]] = i

        for i in range(len(nums)):
            if nums[i] + k in dict and dict[nums[i] + k] != i:
                ans += 1
                del dict[nums[i] + k]

        return ans
