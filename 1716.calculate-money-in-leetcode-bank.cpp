class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        int total = (weeks * 7 * (2 * 1 + (weeks - 1))) / 2 + 7 * (weeks * (weeks - 1) / 2);

        total = 28 * weeks + 7 * (weeks * (weeks - 1)) / 2;

        int start = weeks + 1;
        for (int i = 0; i < days; i++) {
            total += start + i;
        }

        return total;
    }
};