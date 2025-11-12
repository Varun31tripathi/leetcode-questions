#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size(), sum = 0, f = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }
        long long res = f;
        for (int i = n - 1; i > 0; i--) {
            f += sum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }
};
