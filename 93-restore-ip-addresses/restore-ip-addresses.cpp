class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        function<void(int,int)> dfs = [&](int pos,int dots) {
            if(dots == 4 && pos == s.size()) {
                result.push_back(current.substr(0,current.size()-1));
                return;
            }
            if(dots > 4) return;
            for(int len=1; len<=3; ++len) {
                if(pos+len > s.size()) break;
                string part = s.substr(pos,len);
                if((part[0]=='0' && part.size()>1) || stoi(part)>255) continue;
                current += part + '.';
                dfs(pos+len,dots+1);
                current.resize(current.size()-len-1);
            }
        };
        dfs(0,0);
        return result;
    }
};
