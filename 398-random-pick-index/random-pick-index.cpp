#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        auto& v = mp[target];
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, v.size() - 1);
        return v[dis(gen)];
    }
};
