#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, total = 0;
        for (string row : bank) {
            int devices = count(row.begin(), row.end(), '1');
            if (devices > 0) {
                total += prev * devices;
                prev = devices;
            }
        }
        return total;
    }
};