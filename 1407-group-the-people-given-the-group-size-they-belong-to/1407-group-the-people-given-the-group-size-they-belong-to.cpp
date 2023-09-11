class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        
        for(int i=0;i<mp.size();i++){
            int x = 0;
            while(x<mp[i].size()){
                vector<int> slice = {mp[i].begin()+x, mp[i].begin()+x+i};
                groups.push_back(slice);
                x+=i;
            }
        }

        return groups;
    }
};