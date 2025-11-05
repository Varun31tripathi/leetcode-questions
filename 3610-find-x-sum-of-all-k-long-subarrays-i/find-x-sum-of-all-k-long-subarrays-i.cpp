#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int,int> freq;
            for (int j = i; j < i + k; j++) freq[nums[j]]++;
            vector<pair<int,int>> v;
            for (auto &p : freq) v.push_back(p);
            sort(v.begin(), v.end(), [](auto &a, auto &b){
                if (a.second != b.second) return a.second > b.second;
                return a.first > b.first;
            });
            int sum = 0;
            for (int j = 0; j < min(x, (int)v.size()); j++)
                sum += v[j].first * v[j].second;
            res.push_back(sum);
        }
        return res;
    }
};

