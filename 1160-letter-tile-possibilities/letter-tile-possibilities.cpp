#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& cnt) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            ans++;
            cnt[i]--;
            dfs(cnt);
            cnt[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> cnt(26, 0);
        for (char c : tiles) cnt[c - 'A']++;
        dfs(cnt);
        return ans;
    }
};
