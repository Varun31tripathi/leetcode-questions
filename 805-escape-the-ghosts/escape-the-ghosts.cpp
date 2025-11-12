#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int playerDist = abs(target[0]) + abs(target[1]);
        for (auto& g : ghosts) {
            int ghostDist = abs(g[0] - target[0]) + abs(g[1] - target[1]);
            if (ghostDist <= playerDist) return false;
        }
        return true;
    }
};
