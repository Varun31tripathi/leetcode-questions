#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int even = 0, odd = 0;
        for (int x : pos) {
            if (x % 2) odd++;
            else even++;
        }
        return min(even, odd);
    }
};
