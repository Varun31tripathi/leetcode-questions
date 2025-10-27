#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1; // first element always 1
        
        for (int i = 1; i <= rowIndex; i++) {
            // update backwards to not overwrite needed values
            for (int j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};
