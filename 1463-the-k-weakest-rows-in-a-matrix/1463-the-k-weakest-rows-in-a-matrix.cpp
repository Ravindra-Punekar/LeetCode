class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n; i++){
            int soldiers=0;
            for(int j=0;j<m; j++){
                if(mat[i][j]==1) soldiers++;
            }
            pq.push({soldiers, i});
        }

        vector<int> weakest;
        while(k--){
            auto r = pq.top(); pq.pop();
            weakest.push_back(r.second);
        }
        return weakest;
    }
};