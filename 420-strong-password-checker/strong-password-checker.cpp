class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();
        bool lower = false, upper = false, digit = false;
        for (char c : s) {
            if (islower(c)) lower = true;
            else if (isupper(c)) upper = true;
            else if (isdigit(c)) digit = true;
        }
        int missing = (!lower) + (!upper) + (!digit);

        vector<int> repeat;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            if (len >= 3) repeat.push_back(len);
            i = j;
        }

        if (n < 6) return max(missing, 6 - n);

        int over = max(0, n - 20);
        int toDelete = over;
        int replace = 0;

        // Step 1: delete from mod 3 == 0 groups first
        for (int i = 0; i < repeat.size() && toDelete > 0; i++) {
            if (repeat[i] < 3) continue;
            if (repeat[i] % 3 == 0) {
                int use = min(toDelete, 1);
                repeat[i] -= use;
                toDelete -= use;
            }
        }
        // Step 2: then from mod 3 == 1 groups
        for (int i = 0; i < repeat.size() && toDelete > 0; i++) {
            if (repeat[i] < 3) continue;
            if (repeat[i] % 3 == 1) {
                int use = min(toDelete, 2);
                repeat[i] -= use;
                toDelete -= use;
            }
        }
        // Step 3: then from others (mod 2)
        for (int i = 0; i < repeat.size() && toDelete > 0; i++) {
            if (repeat[i] < 3) continue;
            int use = min(toDelete, repeat[i] - 2);
            repeat[i] -= use;
            toDelete -= use;
        }

        // Count remaining replacements
        for (int len : repeat)
            if (len >= 3) replace += len / 3;

        return over + max(missing, replace);
    }
};
