class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        vector<string> result;
        
        if (s.size() < 10) return result;
        
        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            freq[sub]++;
            if (freq[sub] == 2)  // add only once
                result.push_back(sub);
        }
        
        return result;
    }
};

