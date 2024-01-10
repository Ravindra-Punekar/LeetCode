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
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adjList;
        queue<TreeNode*> q;
        q.push(root);

        //1. Convert tree to graph
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                q.push(curr->left);
                adjList[curr->val].push_back(curr->left->val);
                adjList[curr->left->val].push_back(curr->val);
            }
            if (curr->right) {
                q.push(curr->right);
                adjList[curr->val].push_back(curr->right->val);
                adjList[curr->right->val].push_back(curr->val);
            }
        }
        
        // 2. calculate dist.
        unordered_map<int, int> minutes;
        queue<int> bfsQueue;
        unordered_set<int> visited;

        bfsQueue.push(start);
        minutes[start] = 0;
        visited.insert(start);

        while (!bfsQueue.empty()) {
            int current = bfsQueue.front();
            bfsQueue.pop();

            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    bfsQueue.push(neighbor);
                    minutes[neighbor] = minutes[current] + 1;
                }
            }
        }

        int maxMinutes = 0;
        for (const auto& entry : minutes) {
            maxMinutes = max(maxMinutes, entry.second);
        }

        return maxMinutes;
     
    }
};
   /* //see graph
        for(auto it:mp){
            cout<<it.first<<" -> ";
            for(auto adj: it.second){
                cout<<adj<<", ";
            }
            cout<<endl;
        }
    */