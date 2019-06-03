class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        list = []

        for num in set(nums):
            bisect.insort(list, -num)
            del list[3:]

        return -list[2] if len(list) > 2 else -list[0]
