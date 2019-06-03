class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        sell = 0
        hold = float('-inf')

        for price in prices:
            prev = sell
            sell = max(sell, hold + price)
            hold = max(hold, prev - price - fee)

        return sell
