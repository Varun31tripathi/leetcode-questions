#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if (a + b != b + a) return "";
        return a.substr(0, gcd(a.size(), b.size()));
    }
};
