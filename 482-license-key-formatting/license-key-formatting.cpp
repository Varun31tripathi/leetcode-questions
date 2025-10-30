class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned;
        // Remove dashes and uppercase letters
        for (char c : s) {
            if (c != '-') {
                cleaned += toupper(c);
            }
        }
        
        string result;
        int count = 0;
        
        // Process from end
        for (int i = cleaned.size() - 1; i >= 0; --i) {
            if (count == k) {
                result += '-';
                count = 0;
            }
            result += cleaned[i];
            count++;
        }
        
        // Reverse the string to correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
