class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Subtract 1 to convert from 1-indexed to 0-indexed
            columnNumber--;
            
            // Get the character (A-Z)
            char ch = 'A' + (columnNumber % 26);
            result = ch + result;
            
            // Move to next digit
            columnNumber /= 26;
        }
        
        return result;
    }
};
