class TrieNode {
public:
    TrieNode* children[26];
    string word; // stores complete word at the end node
    TrieNode() {
        memset(children, 0, sizeof(children));
        word = "";
    }
};

class Solution {
private:
    vector<string> result;
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited
        if (i > 0) dfs(board, i - 1, j, node);
        if (i < m - 1) dfs(board, i + 1, j, node);
        if (j > 0) dfs(board, i, j - 1, node);
        if (j < n - 1) dfs(board, i, j + 1, node);
        board[i][j] = c; // restore
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        // Build Trie
        TrieNode* root = new TrieNode();
        for (string &word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a'])
                    node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->word = word;
        }

        // DFS search
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, root);

        return result;
    }
};
