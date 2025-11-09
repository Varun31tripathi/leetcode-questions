/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        while (!q.empty()) {
            int size = q.size();
            TreeNode *px = nullptr, *py = nullptr;
            for (int i = 0; i < size; ++i) {
                auto [node, parent] = q.front();
                q.pop();
                if (node->val == x) px = parent;
                if (node->val == y) py = parent;
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
            if (px && py) return px != py;
            if ((px && !py) || (!px && py)) return false;
        }
        return false;
    }
};
