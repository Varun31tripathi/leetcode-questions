class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // Move left pointer if not alphanumeric
            while (left < right && !isalnum(s[left])) left++;
            // Move right pointer if not alphanumeric
            while (left < right && !isalnum(s[right])) right--;
            
            // Compare lowercase characters
            if (tolower(s[left]) != tolower(s[right])) 
                return false;
            
            left++;
            right--;
        }
        return true;
    }
};
