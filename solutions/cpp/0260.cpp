class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> ans(2);

    int xor_ = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    xor_ &= -xor_;

    for (int num : nums) {
      if (num & xor_)
        ans[0] ^= num;
      else
        ans[1] ^= num;
    }

    return ans;
  }
};