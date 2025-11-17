#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &e : connections) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> res;
        int timer = 0;
        function<void(int,int)> dfs = [&](int u, int p){
            disc[u] = low[u] = timer++;
            for (int v : adj[u]) {
                if (v == p) continue;
                if (disc[v] == -1) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > disc[u]) res.push_back({u, v});
                } else {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };
        for (int i = 0; i < n; ++i) if (disc[i] == -1) dfs(i, -1);
        return res;
    }
};
