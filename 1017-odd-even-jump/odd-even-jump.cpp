class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> odd(n), even(n);
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return arr[i] == arr[j] ? i < j : arr[i] < arr[j];
        });
        buildNext(idx, odd);

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return arr[i] == arr[j] ? i < j : arr[i] > arr[j];
        });
        buildNext(idx, even);

        vector<int> goodOdd(n), goodEven(n);
        goodOdd[n - 1] = goodEven[n - 1] = 1;

        for (int i = n - 2; i >= 0; --i) {
            if (odd[i] != -1) goodOdd[i] = goodEven[odd[i]];
            if (even[i] != -1) goodEven[i] = goodOdd[even[i]];
        }

        return accumulate(goodOdd.begin(), goodOdd.end(), 0);
    }

    void buildNext(vector<int>& idx, vector<int>& nxt) {
        int n = idx.size();
        vector<int> stack;
        nxt.assign(n, -1);
        for (int i : idx) {
            while (!stack.empty() && stack.back() < i) {
                nxt[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
    }
};
