class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if k >= len(prices) // 2:
            sell = 0
            hold = float('-inf')

            for price in prices:
                prev = sell
                sell = max(sell, hold + price)
                hold = max(hold, prev - price)

            return sell

        sell = [0] * (k + 1)
        hold = [float('-inf')] * (k + 1)

        for price in prices:
            for i in range(k, 0, -1):
                sell[i] = max(sell[i], hold[i] + price)
                hold[i] = max(hold[i], sell[i - 1] - price)

        return sell[k]
