class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y, distance = 0;
        while(xorVal) {
            distance += xorVal & 1;
            xorVal >>= 1;
        }
        return distance;
    }
};

