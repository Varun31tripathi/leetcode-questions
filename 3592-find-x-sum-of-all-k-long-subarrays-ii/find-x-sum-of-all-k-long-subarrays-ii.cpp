#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> res;
        unordered_map<int,int> freq;
        multiset<pair<int,int>> top, rest;
        long long topSum = 0;

        auto add = [&](int num) {
            int f = ++freq[num];
            auto it = rest.find({f - 1, num});
            if (it != rest.end()) rest.erase(it);
            it = top.find({f - 1, num});
            if (it != top.end()) { top.erase(it); topSum -= 1LL * (f - 1) * num; }

            rest.insert({f, num});
            if ((int)top.size() < x) {
                auto it2 = prev(rest.end());
                top.insert(*it2); topSum += 1LL * it2->first * it2->second; rest.erase(it2);
            } else if (!top.empty() && *rest.rbegin() > *top.begin()) {
                auto itTop = top.begin(), itRest = prev(rest.end());
                topSum -= 1LL * itTop->first * itTop->second;
                topSum += 1LL * itRest->first * itRest->second;
                rest.insert(*itTop); top.erase(itTop);
                top.insert(*itRest); rest.erase(itRest);
            }
        };

        auto remove = [&](int num) {
            int f = freq[num]--;
            auto it = rest.find({f, num});
            if (it != rest.end()) rest.erase(it);
            else {
                it = top.find({f, num});
                if (it != top.end()) { top.erase(it); topSum -= 1LL * f * num; }
            }
            if (f > 1) rest.insert({f - 1, num});
            if ((int)top.size() < x && !rest.empty()) {
                auto it2 = prev(rest.end());
                top.insert(*it2); topSum += 1LL * it2->first * it2->second; rest.erase(it2);
            }
        };

        for (int i = 0; i < k; i++) add(nums[i]);
        res.push_back(topSum);
        for (int i = k; i < n; i++) {
            remove(nums[i - k]);
            add(nums[i]);
            res.push_back(topSum);
        }
        return res;
    }
};