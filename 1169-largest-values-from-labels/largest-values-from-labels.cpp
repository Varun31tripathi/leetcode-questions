class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                              int numWanted, int useLimit) {

        vector<pair<int,int>> items;
        int n = values.size();
        items.reserve(n);

        for (int i = 0; i < n; i++)
            items.push_back({values[i], labels[i]});

        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        unordered_map<int, int> used;
        int sum = 0;
        int taken = 0;

        for (auto &p : items) {
            if (taken == numWanted) break;

            int val = p.first;
            int lab = p.second;

            if (used[lab] < useLimit) {
                sum += val;
                used[lab]++;
                taken++;
            }
        }

        return sum;
    }
};
