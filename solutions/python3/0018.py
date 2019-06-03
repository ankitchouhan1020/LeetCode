class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []

        ans = []

        nums.sort()

        for i in range(len(nums) - 3):
            if i == 0 or nums[i] != nums[i - 1]:
                for j in range(i + 1, len(nums) - 2):
                    if j == i + 1 or nums[j] != nums[j - 1]:
                        l = j + 1
                        r = len(nums) - 1
                        newTarget = target - nums[i] - nums[j]
                        while l < r:
                            if nums[l] + nums[r] == newTarget:
                                ans.append(
                                    [nums[i], nums[j], nums[l], nums[r]])
                                while l < r and nums[l] == nums[l + 1]:
                                    l += 1
                                while l < r and nums[r] == nums[r - 1]:
                                    r -= 1
                                l += 1
                                r -= 1
                            elif nums[l] + nums[r] < newTarget:
                                l += 1
                            else:
                                r -= 1

        return ans
