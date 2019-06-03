class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        sum_ = sum(nums)
        leftSum = 0

        for i, num in enumerate(nums):
            if leftSum == sum_ - leftSum - num:
                return i
            leftSum += num

        return -1
