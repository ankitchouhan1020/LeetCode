class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        ans = 0

        for num in nums:
            if num != float('inf'):
                start = num
                count = 0
                while nums[start] != float('inf'):
                    temp = start
                    start = nums[start]
                    nums[temp] = float('inf')
                    count += 1
                ans = max(ans, count)

        return ans
