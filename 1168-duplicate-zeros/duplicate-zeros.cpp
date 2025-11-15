class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        for (int i = 0; i < n - zeros; i++) {
            if (arr[i] == 0) {
                if (i == n - zeros - 1) {
                    arr[n - 1] = 0;
                    n--;
                    break;
                }
                zeros++;
            }
        }

        int last = n - zeros - 1;

        for (int i = last; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + zeros] = 0;
                zeros--;
                arr[i + zeros] = 0;
            } else {
                arr[i + zeros] = arr[i];
            }
        }
    }
};
