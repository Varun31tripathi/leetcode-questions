class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string word;
        stringstream ss(s1 + " " + s2);
        while (ss >> word) mp[word]++;
        vector<string> res;
        for (auto &p : mp)
            if (p.second == 1) res.push_back(p.first);
        return res;
    }
};
