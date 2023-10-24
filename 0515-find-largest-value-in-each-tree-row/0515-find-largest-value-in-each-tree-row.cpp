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
    void solve(TreeNode* node,int i, vector<int>& ans){
        if(!node){
            return;
        }
        if(i>ans.size()){
            ans.push_back(node->val);
        }else{
            ans[i-1] = max(ans[i-1], node->val);
        }
        solve(node->left, i+1, ans);
        solve(node->right, i+1, ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        solve(root, 1, ans);
        return ans;
    }
};