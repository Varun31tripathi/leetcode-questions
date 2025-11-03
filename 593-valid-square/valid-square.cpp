class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> pts = {p1, p2, p3, p4};
        vector<int> dists;
        for (int i = 0; i < 4; ++i)
            for (int j = i + 1; j < 4; ++j) {
                int dx = pts[i][0] - pts[j][0];
                int dy = pts[i][1] - pts[j][1];
                dists.push_back(dx*dx + dy*dy);
            }
        sort(dists.begin(), dists.end());
        if (dists[0] == 0) return false;
        return dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3]
            && dists[4] == dists[5] && dists[4] == 2 * dists[0];
    }
};
