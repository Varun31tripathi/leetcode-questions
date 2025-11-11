#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (char c : address)
            res += (c == '.') ? "[.]" : string(1, c);
        return res;
    }
};
