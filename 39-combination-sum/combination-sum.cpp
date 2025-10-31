class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        backtrack(candidates, target, 0, cur);
        return ans;
    }
    void backtrack(vector<int>& c, int target, int idx, vector<int>& cur) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0) return;
        for (int i = idx; i < c.size(); i++) {
            cur.push_back(c[i]);
            backtrack(c, target - c[i], i, cur);
            cur.pop_back();
        }
    }
};
