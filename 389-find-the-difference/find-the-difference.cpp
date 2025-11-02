class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorSum = 0;
        for (char c : s) xorSum ^= c;
        for (char c : t) xorSum ^= c;
        return (char)xorSum;
    }
};
