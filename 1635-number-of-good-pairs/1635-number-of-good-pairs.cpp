class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        for(auto it:mp){
           if(it.second>=2) 
            count += ((it.second)*(it.second-1)/2);
        }
        return count;
    }
};