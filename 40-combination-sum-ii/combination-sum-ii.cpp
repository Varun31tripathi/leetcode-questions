class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrack(candidates, target, 0, cur);
        return ans;
    }
    void backtrack(vector<int>& c, int target, int idx, vector<int>& cur) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = idx; i < c.size(); i++) {
            if (i > idx && c[i] == c[i - 1]) continue;
            if (c[i] > target) break;
            cur.push_back(c[i]);
            backtrack(c, target - c[i], i + 1, cur);
            cur.pop_back();
        }
    }
};
