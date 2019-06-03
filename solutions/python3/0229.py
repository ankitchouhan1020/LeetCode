class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        ans = []
        dict = collections.Counter(nums)

        for key, value in dict.items():
            if value > len(nums) // 3:
                ans.append(key)

        return ans
