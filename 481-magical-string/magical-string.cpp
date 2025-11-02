class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1;
        string s = "122";
        int i = 2, count = 1;
        while (s.size() < n) {
            char next = s.back() == '1' ? '2' : '1';
            int times = s[i] - '0';
            for (int j = 0; j < times; ++j) s.push_back(next);
            if (next == '1') count += min(times, n - (int)s.size() + times);
            i++;
        }
        return count;
    }
};
