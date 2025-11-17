#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,long long> mp;
        long long ans = 0, mod = 1000000007;

        for (int x : nums) {
            int key = x - reverseNum(x);
            ans = (ans + mp[key]) % mod;
            mp[key]++;
        }
        return ans;
    }
};
