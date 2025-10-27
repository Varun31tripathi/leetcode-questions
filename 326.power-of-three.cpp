class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base case: numbers <= 0 cannot be powers of 3
        if (n <= 0) return false;
        
        // Keep dividing by 3 while divisible
        while (n % 3 == 0) {
            n /= 3;
        }
        
        // If we end up with 1, it was a power of 3
        return n == 1;
    }
};
