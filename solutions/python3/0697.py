class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        ans = len(nums)
        left = {}
        right = {}
        dict = collections.defaultdict(int)

        for i, num in enumerate(nums):
            if num not in left:
                left[num] = i
            right[num] = i
            dict[num] += 1

        degree = max(dict.values())

        for key, value in dict.items():
            if value == degree:
                ans = min(ans, right[key] - left[key] + 1)

        return ans
