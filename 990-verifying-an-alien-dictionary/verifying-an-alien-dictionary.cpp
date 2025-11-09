class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(26);
        for (int i = 0; i < 26; ++i) pos[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; ++i)
            if (!check(words[i], words[i + 1], pos))
                return false;
        return true;
    }
    
    bool check(const string& a, const string& b, vector<int>& pos) {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i])
                return pos[a[i] - 'a'] < pos[b[i] - 'a'];
        }
        return a.size() <= b.size();
    }
};
