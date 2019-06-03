class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)

        j = 0

        for i in range(len(nums)):
            if nums[i] != nums[j]:
                j += 1
                nums[j] = nums[i]

        return j + 1
