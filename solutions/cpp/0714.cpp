class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int sell = 0;
    int hold = INT_MIN;

    for (int price : prices) {
      int prev = sell;
      sell = max(sell, hold + price);
      hold = max(hold, prev - price - fee);
    }

    return sell;
  }
};