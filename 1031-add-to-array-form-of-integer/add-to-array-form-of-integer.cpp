class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1, carry = 0;
        vector<int> res;
        while (i >= 0 || k > 0) {
            int sum = carry;
            if (i >= 0) sum += num[i--];
            sum += k % 10;
            k /= 10;
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
