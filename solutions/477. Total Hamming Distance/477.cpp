class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    constexpr int maxMask = 1 << 30;
    int ans = 0;

    for (int mask = 1; mask < maxMask; mask <<= 1) {
      const int ones =
          ranges::count_if(nums, [mask](int num) { return num & mask; });
      const int zeros = nums.size() - ones;
      ans += ones * zeros;
    }

    return ans;
  }
};
