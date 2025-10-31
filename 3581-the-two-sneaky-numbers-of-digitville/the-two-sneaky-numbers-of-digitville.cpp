class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> ans;
        for (int x : nums) {
            if (s.count(x)) ans.push_back(x);
            s.insert(x);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
