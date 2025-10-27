class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: empty tree
        if (root == nullptr) {
            return false;
        }
        
        // Check if we're at a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Recursively check left and right subtrees
        // Subtract current node's value from targetSum
        int remainingSum = targetSum - root->val;
        
        return hasPathSum(root->left, remainingSum) || 
               hasPathSum(root->right, remainingSum);
    }
};
