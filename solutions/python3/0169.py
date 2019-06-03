class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)

        dict = collections.defaultdict(int)

        for num in nums:
            dict[num] += 1
            if dict[num] > n // 2:
                return num
