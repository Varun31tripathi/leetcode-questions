class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1, pos = n - 1;
        while (l <= r) {
            int left = nums[l] * nums[l];
            int right = nums[r] * nums[r];
            if (left > right) {
                res[pos--] = left;
                ++l;
            } else {
                res[pos--] = right;
                --r;
            }
        }
        return res;
    }
};
