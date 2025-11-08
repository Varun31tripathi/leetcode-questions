class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> copy = board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (auto& d : dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && copy[x][y] == 1) live++;
                }
                if (copy[i][j] == 1 && (live < 2 || live > 3)) board[i][j] = 0;
                if (copy[i][j] == 0 && live == 3) board[i][j] = 1;
            }
        }
    }
};
