/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int min, int mx) {
        if (!root)
            return 0;
        if (root->val > mx)
            mx = root->val;
        if (root->val < min)
            min = root->val;

        int diff = max((mx - min), max(
                        solve(root->left, min, mx),
                        solve(root->right, min, mx)));
                        
        return diff;
    }

    int maxAncestorDiff(TreeNode* root) {
        int min = root->val;
        int max = root->val;
        int ans = solve(root, min, max);
        return ans;
    }
};