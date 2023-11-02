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
    int c=0;
    pair<int,int> tSum(TreeNode* root){
        if(root==NULL) return {0,0};
        
        auto ls = tSum(root->left);
        auto rs = tSum(root->right);

        int n = 1 + ls.second + rs.second;
        int sum = root->val+ls.first+rs.first;
        c += (root->val == sum/n);
        
        // cout<<root->val<<" == "<<sum<<"/"<<n<<"? -"<<c<<endl;
        return {sum, n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        tSum(root);
        return c;
    }
};