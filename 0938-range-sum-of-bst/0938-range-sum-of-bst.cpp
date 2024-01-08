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
    void dsf(TreeNode* node, int low, int high, int &sum ){
        if(!node) return;
        sum += (node->val>= low && node->val <= high)?
                node->val : 0;
        dsf(node->left, low, high, sum);
        dsf(node->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        dsf(root, low, high, sum);
        return sum;
    }
};