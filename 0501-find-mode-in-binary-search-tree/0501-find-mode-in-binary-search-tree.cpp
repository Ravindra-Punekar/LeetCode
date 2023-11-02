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
    void dsf(TreeNode* node, unordered_map<int,int> &mp){
        if(!node) return;
        mp[node->val]++;
        dsf(node->left, mp);
        dsf(node->right, mp);
    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b){ 
        return a.second > b.second; 
    } 
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        dsf(root,mp);

        vector<pair<int, int> > A;  
        for (auto& it : mp) { 
            A.push_back(it); 
        } 
        sort(A.begin(), A.end(), cmp); 
        int maxCount = A[0].second;
        vector<int>ans;
        int i=0;
        while(i<A.size() && A[i].second==maxCount){
            ans.push_back(A[i++].first);
        }
        return ans;
    }
};