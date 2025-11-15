class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for (auto &t : trips) {
            int num = t[0];
            int from = t[1];
            int to = t[2];

            diff[from] += num;
            diff[to] -= num;
        }

        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += diff[i];
            if (curr > capacity)
                return false;
        }

        return true;
    }
};
