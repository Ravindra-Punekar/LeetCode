class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second;
    }

    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n:nums)
            mp[n]++;
            
        vector<pair<int,int>> v;
        for(auto it:mp)
            v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        
        vector<vector<int>> ans(v[0].second, vector<int>(0));

        for(auto p:v){
            for(int i=0;i<p.second; i++){
                ans[i].push_back(p.first);
            }
        }

        return ans;
    }
};