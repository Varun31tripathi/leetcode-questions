class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        long long l = 1, r = num;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long sq = m * m;
            if (sq == num) return true;
            if (sq < num) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
};
