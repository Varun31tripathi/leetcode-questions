#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--];
            if (j >= 0) sum += b[j--];

            res.push_back((sum & 1) ? 1 : 0);
            carry = -(sum >> 1);
        }

        while (res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
