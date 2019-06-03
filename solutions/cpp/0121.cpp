class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sellOne = 0;
    int holdOne = INT_MIN;

    for (int price : prices) {
      sellOne = max(sellOne, holdOne + price);
      holdOne = max(holdOne, -price);
    }

    return sellOne;
  }
};