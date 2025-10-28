class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        for (char c : columnTitle) {
            int value = c - 'A' + 1;      // Convert letter to number (A=1, B=2, ...)
            result = result * 26 + value; // Shift left in base-26
        }
        return result;
    }
};
