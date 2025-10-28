#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        int l = 0;  // sum of non-zero elements to left of current position
        for (int x : nums) {
            if (x != 0) {
                l += x;
            } else {
                int r = s - l;
                if (l == r) {
                    ans += 2;
                } else if (abs(l - r) == 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
