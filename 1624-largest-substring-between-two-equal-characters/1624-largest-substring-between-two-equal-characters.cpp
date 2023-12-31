class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLen = 0;
        unordered_map<char,vector<int>> mp;

        for(int i=0;i<s.size();i++) 
            mp[s[i]].push_back(i);

        for(auto it:mp){
            maxLen = max(maxLen, (*it.second.rbegin()-*it.second.begin()));
        }
        
        return maxLen-1;

    }
};