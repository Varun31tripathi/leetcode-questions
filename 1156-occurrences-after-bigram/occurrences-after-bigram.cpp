#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words, res;
        stringstream ss(text);
        string w;
        while (ss >> w) words.push_back(w);
        for (int i = 0; i + 2 < words.size(); ++i)
            if (words[i] == first && words[i + 1] == second)
                res.push_back(words[i + 2]);
        return res;
    }
};
