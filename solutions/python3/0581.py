class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        min_ = float('inf')
        max_ = float('-inf')
        flag = False

        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                flag = True
            if flag:
                min_ = min(min_, nums[i])

        flag = False

        for i in range(len(nums) - 2, -1, -1):
            if nums[i] > nums[i + 1]:
                flag = True
            if flag:
                max_ = max(max_, nums[i])

        for l in range(len(nums)):
            if nums[l] > min_:
                break

        for r in range(len(nums) - 1, -1, -1):
            if nums[r] < max_:
                break

        return 0 if r - l <= 0 else r - l + 1
