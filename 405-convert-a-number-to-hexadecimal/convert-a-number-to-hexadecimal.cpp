class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        unsigned int n = num; // handle negatives using unsigned
        string hexChars = "0123456789abcdef";
        string result = "";

        while (n > 0) {
            int digit = n & 15;           // get last 4 bits
            result.push_back(hexChars[digit]);
            n >>= 4;                      // move to next 4 bits
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
