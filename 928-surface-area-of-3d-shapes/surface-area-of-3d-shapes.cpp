class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j]) ans += 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = grid[i][j];
                int up = (i == 0 ? 0 : grid[i-1][j]);
                int down = (i == n-1 ? 0 : grid[i+1][j]);
                int left = (j == 0 ? 0 : grid[i][j-1]);
                int right = (j == m-1 ? 0 : grid[i][j+1]);
                ans += max(0, v - up) + max(0, v - down) + max(0, v - left) + max(0, v - right);
            }
        }
        return ans;
    }
};
