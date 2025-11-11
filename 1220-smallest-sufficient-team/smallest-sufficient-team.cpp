#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        unordered_map<string,int> id;
        for (int i = 0; i < m; ++i) id[req_skills[i]] = i;
        int M = 1 << m;
        vector<vector<int>> dp(M); // dp[mask] = smallest team (list of indices) to achieve mask
        dp[0] = {};
        for (int i = 0; i < (int)people.size(); ++i) {
            int pmask = 0;
            for (auto &s : people[i]) if (id.count(s)) pmask |= 1 << id[s];
            if (pmask == 0) continue;
            auto prev = dp;
            for (int mask = 0; mask < M; ++mask) {
                if (prev[mask].empty() && mask != 0) continue;
                int comb = mask | pmask;
                if (dp[comb].empty() || prev[mask].size() + 1 < dp[comb].size()) {
                    dp[comb] = prev[mask];
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[M - 1];
    }
};
