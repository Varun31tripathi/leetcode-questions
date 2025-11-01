class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0); // ASCII
        for (char c : s) count[c]++;
        
        int length = 0;
        bool odd = false;
        for (int c : count) {
            if (c % 2 == 0) length += c;
            else {
                length += c - 1;
                odd = true;
            }
        }
        return odd ? length + 1 : length;
    }
};

