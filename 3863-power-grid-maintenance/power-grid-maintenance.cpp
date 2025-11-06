#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct DSU {
        int n; vector<int> p;
        DSU(int n): n(n), p(n + 1) { iota(p.begin(), p.end(), 0); }
        int find(int a){ return p[a]==a?a:p[a]=find(p[a]); }
        void unite(int a,int b){ a=find(a); b=find(b); if(a!=b)p[b]=a; }
    };
public:
    vector<int> processQueries(int c, vector<vector<int>>& cables, vector<vector<int>>& queries) {
        DSU dsu(c);
        for(auto &e:cables) dsu.unite(e[0],e[1]);
        vector<set<int>> comp(c+1);
        for(int i=1;i<=c;i++) comp[dsu.find(i)].insert(i);
        vector<bool> online(c+1,true);
        vector<int> ans;
        for(auto &q:queries){
            int type=q[0],x=q[1];
            if(type==1){
                int f=dsu.find(x);
                if(online[x]) ans.push_back(x);
                else ans.push_back(comp[f].empty()?-1:*comp[f].begin());
            }else{
                if(online[x]){
                    int f=dsu.find(x);
                    comp[f].erase(x);
                    online[x]=false;
                }
            }
        }
        return ans;
    }
};
