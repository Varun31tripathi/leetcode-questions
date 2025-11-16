#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);

        long long l = 1, r = 2e18;
        while (l < r) {
            long long m = (l + r) / 2;
            long long cnt = m / a + m / b + m / c
                            - m / ab - m / bc - m / ac
                            + m / abc;
            if (cnt >= n) r = m;
            else l = m + 1;
        }
        return l;
    }
};
