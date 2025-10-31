class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;

        int len1 = s1.size(), len2 = s2.size();
        vector<int> repeatCount(n1 + 1, 0);
        vector<int> nextIndex(n1 + 1, 0);
        int j = 0, cnt = 0;

        for (int k = 1; k <= n1; k++) {
            for (int i = 0; i < len1; i++) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        cnt++;
                    }
                }
            }
            repeatCount[k] = cnt;
            nextIndex[k] = j;

            for (int start = 0; start < k; start++) {
                if (nextIndex[start] == j) {
                    int prefixCount = repeatCount[start];
                    int patternCount = (repeatCount[k] - repeatCount[start]);
                    int patternLength = k - start;
                    int remaining = n1 - start;
                    int totalCount = prefixCount + (remaining / patternLength) * patternCount;
                    int leftover = remaining % patternLength;
                    totalCount += repeatCount[start + leftover] - repeatCount[start];
                    return totalCount / n2;
                }
            }
        }

        return repeatCount[n1] / n2;
    }
};
