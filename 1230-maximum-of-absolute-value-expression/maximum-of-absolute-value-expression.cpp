#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int mx1 = INT_MIN, mn1 = INT_MAX;
        int mx2 = INT_MIN, mn2 = INT_MAX;
        int mx3 = INT_MIN, mn3 = INT_MAX;
        int mx4 = INT_MIN, mn4 = INT_MAX;

        for (int i = 0; i < n; i++) {
            mx1 = max(mx1,  a[i] + b[i] + i);
            mn1 = min(mn1,  a[i] + b[i] + i);

            mx2 = max(mx2,  a[i] + b[i] - i);
            mn2 = min(mn2,  a[i] + b[i] - i);

            mx3 = max(mx3,  a[i] - b[i] + i);
            mn3 = min(mn3,  a[i] - b[i] + i);

            mx4 = max(mx4,  a[i] - b[i] - i);
            mn4 = min(mn4,  a[i] - b[i] - i);
        }

        return max({mx1 - mn1, mx2 - mn2, mx3 - mn3, mx4 - mn4});
    }
};
