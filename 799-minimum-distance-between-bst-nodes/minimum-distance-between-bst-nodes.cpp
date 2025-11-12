#include <bits/stdc++.h>
using namespace std;

class Solution {
    int prevVal = -1, ans = INT_MAX;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (prevVal != -1) ans = min(ans, root->val - prevVal);
        prevVal = root->val;
        dfs(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
