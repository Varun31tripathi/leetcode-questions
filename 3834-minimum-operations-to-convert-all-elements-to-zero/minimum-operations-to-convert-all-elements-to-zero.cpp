class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> st = {0};
        for (int num : nums) {
            while (!st.empty() && st.back() > num) st.pop_back();
            if (st.back() < num) {
                ans++;
                st.push_back(num);
            }
        }
        return ans;
    }
};
