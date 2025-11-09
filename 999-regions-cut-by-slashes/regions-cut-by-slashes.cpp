class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = n * 3;
        vector<vector<int>> expanded(size, vector<int>(size, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    expanded[i * 3][j * 3 + 2] = 1;
                    expanded[i * 3 + 1][j * 3 + 1] = 1;
                    expanded[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    expanded[i * 3][j * 3] = 1;
                    expanded[i * 3 + 1][j * 3 + 1] = 1;
                    expanded[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        
        int regions = 0;
        vector<vector<bool>> vis(size, vector<bool>(size, false));
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!expanded[i][j] && !vis[i][j]) {
                    dfs(expanded, vis, i, j);
                    ++regions;
                }
            }
        }
        return regions;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j]) return;
        vis[i][j] = true;
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i, j + 1);
        dfs(grid, vis, i, j - 1);
    }
};
