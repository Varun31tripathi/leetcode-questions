class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j)
                    overlap[i][j] = getOverlap(words[i], words[j]);
        
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        
        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = words[i].size();
        
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j))) continue;
                int pmask = mask ^ (1 << j);
                if (pmask == 0) continue;
                for (int i = 0; i < n; ++i) {
                    if (!(pmask & (1 << i))) continue;
                    int val = dp[pmask][i] + (int)words[j].size() - overlap[i][j];
                    if (val < dp[mask][j]) {
                        dp[mask][j] = val;
                        parent[mask][j] = i;
                    }
                }
            }
        }
        
        int mask = (1 << n) - 1;
        int last = 0;
        for (int i = 0; i < n; ++i)
            if (dp[mask][i] < dp[mask][last])
                last = i;
        
        string res;
        vector<int> path;
        while (last != -1) {
            path.push_back(last);
            int temp = parent[mask][last];
            mask ^= (1 << last);
            last = temp;
        }
        reverse(path.begin(), path.end());
        
        res = words[path[0]];
        for (int i = 1; i < path.size(); ++i) {
            int o = overlap[path[i - 1]][path[i]];
            res += words[path[i]].substr(o);
        }
        return res;
    }
    
    int getOverlap(const string& a, const string& b) {
        int len = min(a.size(), b.size());
        for (int k = len; k > 0; --k)
            if (a.substr(a.size() - k) == b.substr(0, k))
                return k;
        return 0;
    }
};
