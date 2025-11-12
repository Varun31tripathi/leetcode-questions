#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> orig, curr;
public:
    Solution(vector<int>& nums) {
        orig = nums;
        curr = nums;
    }
    
    vector<int> reset() {
        curr = orig;
        return curr;
    }
    
    vector<int> shuffle() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(curr.begin(), curr.end(), g);
        return curr;
    }
};
