class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)

        ans = []
        i = 0

        while i < n:
            start = nums[i]
            while i < n - 1 and nums[i] == nums[i + 1] - 1:
                i += 1
            end = nums[i]
            if start == end:
                ans.append(str(start))
            else:
                ans.append(str(start) + "->" + str(end))
            i += 1

        return ans
