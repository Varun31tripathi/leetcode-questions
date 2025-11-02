class Solution {
public:
    int modPow(int a, int k, int mod) {
        int res = 1;
        a %= mod;
        while (k) {
            if (k & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            k >>= 1;
        }
        return res;
    }
    
    int superPow(int a, vector<int>& b) {
        const int mod = 1337;
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        int part1 = modPow(a, last, mod);
        int part2 = modPow(superPow(a, b), 10, mod);
        return (part1 * part2) % mod;
    }
};

