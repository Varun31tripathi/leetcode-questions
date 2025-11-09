class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flips = 0, cur = 0;
        vector<int> isFlipped(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i >= k) cur ^= isFlipped[i - k];
            if (nums[i] == cur) {
                if (i + k > n) return -1;
                isFlipped[i] = 1;
                cur ^= 1;
                ++flips;
            }
        }
        return flips;
    }
};
