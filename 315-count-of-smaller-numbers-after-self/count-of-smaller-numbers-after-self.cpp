#include <bits/stdc++.h>
using namespace std;

class Solution {
    void mergeCount(vector<pair<int,int>>& nums, int l, int r, vector<int>& res) {
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        mergeCount(nums, l, m, res);
        mergeCount(nums, m, r, res);
        int j = m;
        vector<pair<int,int>> temp;
        for (int i = l; i < m; i++) {
            while (j < r && nums[j].first < nums[i].first) j++;
            res[nums[i].second] += j - m;
        }
        inplace_merge(nums.begin() + l, nums.begin() + m, nums.begin() + r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++) arr.push_back({nums[i], i});
        vector<int> res(n, 0);
        mergeCount(arr, 0, n, res);
        return res;
    }
};
