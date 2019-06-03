class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        set_ = set(nums)

        for num in set_:
            if num - 1 not in set_:
                currNum = num
                currAns = 1
                while currNum + 1 in set_:
                    currNum += 1
                    currAns += 1
                ans = max(ans, currAns)

        return ans
