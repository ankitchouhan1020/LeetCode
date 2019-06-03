class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        gaussSum = n * (n + 1) // 2

        return gaussSum - sum(nums)
