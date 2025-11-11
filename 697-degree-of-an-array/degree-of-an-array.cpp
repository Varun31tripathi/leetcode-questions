#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first;
        int degree = 0, res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (!first.count(nums[i])) first[nums[i]] = i;
            count[nums[i]]++;
            degree = max(degree, count[nums[i]]);
        }
        unordered_map<int, int> last;
        for (int i = 0; i < nums.size(); ++i) last[nums[i]] = i;
        for (auto& [num, c] : count)
            if (c == degree) res = min(res, last[num] - first[num] + 1);
        return res;
    }
};
