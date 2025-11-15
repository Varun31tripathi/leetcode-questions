class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        long long ans = 0;

        // prefix ones count
        vector<int> one(n+1);
        for(int i = 0; i < n; i++)
            one[i+1] = one[i] + (s[i] == '1');

        // zero positions
        vector<int> z;
        for(int i = 0; i < n; i++)
            if(s[i] == '0') z.push_back(i);

        int Z = z.size();
        z.insert(z.begin(), -1);
        z.push_back(n);

        // z = 0 → pure ones segments
        for(int i = 1; i < (int)z.size(); i++) {
            long long len = z[i] - z[i-1] - 1;
            ans += len * (len + 1) / 2;
        }

        // z >= 1 windows
        int maxZ = (int) sqrt(n) + 2;
        for(int k = 1; k <= maxZ && k <= Z; k++) {

            for(int i = 1; i + k - 1 <= Z; i++) {
                int leftZero  = z[i-1];
                int firstZero = z[i];
                int lastZero  = z[i+k-1];
                int rightZero = z[i+k];

                long long L = firstZero - leftZero - 1;   // ones before window
                long long R = rightZero - lastZero - 1;   // ones after window

                long long totalLen = rightZero - leftZero - 1;
                long long totalOnes = totalLen - k;

                long long internalOnes = totalOnes - L - R;

                long long need = 1LL * k * k;
                long long T = need - internalOnes;    // need x+y >= T  

                if(T <= 0) {                          // everything valid
                    ans += (L + 1) * (R + 1);
                    continue;
                }

                long long S = T - 1;                  // pairs with sum ≤ S are invalid
                long long totalPairs = (L + 1) * (R + 1);

                if(S >= L + R)                        // all pairs invalid
                    continue;

                long long X = min<long long>(L, S);
                long long bad = 0;

                if(X >= 0) {
                    long long cutoff = S - R;
                    if(cutoff >= 0) {
                        long long a = min<long long>(X, cutoff);
                        bad += (a + 1) * (R + 1);

                        long long start = a + 1;
                        if(start <= X) {
                            long long m = X - start + 1;
                            long long f = S - start + 1;
                            long long l = S - X + 1;
                            bad += m * (f + l) / 2;
                        }
                    } else {
                        long long m = X + 1;
                        long long f = S - 0 + 1;
                        long long l = S - X + 1;
                        bad += m * (f + l) / 2;
                    }
                }

                ans += totalPairs - bad;
            }
        }

        return ans;
    }
};
