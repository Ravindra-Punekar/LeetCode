class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mps, mpt;
        
        for(int i=0;i<s.size();i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        
        int count=0;
        for(char ch='a';ch<='z';ch++)
            count += abs(mps[ch]-mpt[ch]);
        
        return count/2;
    }
};