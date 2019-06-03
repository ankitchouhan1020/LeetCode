class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        sum = 0
        dict = collections.defaultdict(int)
        dict[0] = 1

        for num in nums:
            sum += num
            if sum - k in dict:
                ans += dict[sum - k]
            dict[sum] += 1

        return ans
