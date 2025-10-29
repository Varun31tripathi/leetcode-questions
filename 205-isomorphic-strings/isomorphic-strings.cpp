#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(const string &s, const string &t) {
        if (s.size() != t.size()) return false;
        vector<int> map_s_to_t(256, -1);
        vector<int> mapped_t(256, 0);
        for (size_t i = 0; i < s.size(); ++i) {
            unsigned char cs = s[i], ct = t[i];
            if (map_s_to_t[cs] == -1) {
                if (mapped_t[ct]) return false;
                map_s_to_t[cs] = ct;
                mapped_t[ct] = 1;
            } else {
                if (map_s_to_t[cs] != ct) return false;
            }
        }
        return true;
    }
};
