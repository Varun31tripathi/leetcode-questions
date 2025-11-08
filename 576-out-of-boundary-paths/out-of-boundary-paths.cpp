class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][51][51];
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, maxMove, startRow, startColumn);
    }

    int dfs(int m, int n, int moves, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return 1;
        if (moves == 0) return 0;
        if (dp[i][j][moves] != -1) return dp[i][j][moves];
        long res = 0;
        res += dfs(m, n, moves - 1, i - 1, j);
        res += dfs(m, n, moves - 1, i + 1, j);
        res += dfs(m, n, moves - 1, i, j - 1);
        res += dfs(m, n, moves - 1, i, j + 1);
        return dp[i][j][moves] = res % mod;
    }
};
