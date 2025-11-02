class Solution {
public:
    vector<string> split(const string& s, char d) {
        vector<string> res;
        string cur;
        for (char c : s) {
            if (c == d) {
                res.push_back(cur);
                cur.clear();
            } else cur.push_back(c);
        }
        res.push_back(cur);
        return res;
    }

    bool isIPv4(string s) {
        auto parts = split(s, '.');
        if (parts.size() != 4) return false;
        for (auto& p : parts) {
            if (p.empty() || (p.size() > 1 && p[0] == '0')) return false;
            if (p.size() > 3) return false;
            for (char c : p) if (!isdigit(c)) return false;
            int val = stoi(p);
            if (val < 0 || val > 255) return false;
        }
        return true;
    }

    bool isIPv6(string s) {
        auto parts = split(s, ':');
        if (parts.size() != 8) return false;
        for (auto& p : parts) {
            if (p.empty() || p.size() > 4) return false;
            for (char c : p) {
                if (!isxdigit(c)) return false;
            }
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos && isIPv4(queryIP)) return "IPv4";
        if (queryIP.find(':') != string::npos && isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};
