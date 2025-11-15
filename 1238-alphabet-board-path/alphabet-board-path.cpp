class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int x = 0, y = 0;   // starting position at 'a'

        for (char c : target) {
            int idx = c - 'a';
            int nx = idx / 5;
            int ny = idx % 5;

            // If target is 'z', move horizontally first to avoid invalid cell
            if (c == 'z') {
                // move left or right first
                while (y > ny) { ans.push_back('L'); y--; }
                while (y < ny) { ans.push_back('R'); y++; }
                // then move vertically
                while (x > nx) { ans.push_back('U'); x--; }
                while (x < nx) { ans.push_back('D'); x++; }
            } 
            else {
                // Normal case: move vertically first if coming from 'z'
                while (x > nx) { ans.push_back('U'); x--; }
                while (y > ny) { ans.push_back('L'); y--; }
                while (y < ny) { ans.push_back('R'); y++; }
                while (x < nx) { ans.push_back('D'); x++; }
            }

            ans.push_back('!');
        }

        return ans;
    }
};
