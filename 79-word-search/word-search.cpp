class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& b, string& w, int i, int j, int k) {
        if (k == w.size()) return true;
        if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k]) return false;
        char c = b[i][j];
        b[i][j] = '#';
        bool res = dfs(b, w, i+1, j, k+1) || dfs(b, w, i-1, j, k+1) || dfs(b, w, i, j+1, k+1) || dfs(b, w, i, j-1, k+1);
        b[i][j] = c;
        return res;
    }
};

