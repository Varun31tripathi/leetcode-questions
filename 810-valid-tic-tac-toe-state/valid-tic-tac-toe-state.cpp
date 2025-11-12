#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool win(vector<string>& b, char p) {
        for (int i = 0; i < 3; i++)
            if ((b[i][0] == p && b[i][1] == p && b[i][2] == p) ||
                (b[0][i] == p && b[1][i] == p && b[2][i] == p))
                return true;
        if ((b[0][0] == p && b[1][1] == p && b[2][2] == p) ||
            (b[0][2] == p && b[1][1] == p && b[2][0] == p))
            return true;
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;
        for (auto& r : board)
            for (char c : r)
                if (c == 'X') x++;
                else if (c == 'O') o++;
        bool xWin = win(board, 'X'), oWin = win(board, 'O');
        if (o > x || x - o > 1) return false;
        if (xWin && oWin) return false;
        if (xWin && x == o) return false;
        if (oWin && x > o) return false;
        return true;
    }
};
