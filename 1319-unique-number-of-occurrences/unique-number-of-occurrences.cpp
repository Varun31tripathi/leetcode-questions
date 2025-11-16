#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> f;
        for (int x : arr) f[x]++;
        unordered_set<int> s;
        for (auto &p : f) {
            if (s.count(p.second)) return false;
            s.insert(p.second);
        }
        return true;
    }
};
