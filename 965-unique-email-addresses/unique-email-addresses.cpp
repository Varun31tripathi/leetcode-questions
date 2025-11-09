class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto &e : emails) {
            string local, domain;
            int i = 0;
            while (e[i] != '@' && e[i] != '+') {
                if (e[i] != '.') local += e[i];
                ++i;
            }
            while (e[i] != '@') ++i;
            domain = e.substr(i);
            s.insert(local + domain);
        }
        return s.size();
    }
};
