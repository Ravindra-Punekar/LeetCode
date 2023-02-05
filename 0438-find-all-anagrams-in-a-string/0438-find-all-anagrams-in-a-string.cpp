class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> mp, window;
        vector<int> ans;
        
        for(auto c : p)
            mp[c]++;
        
        int i=0, j=0;
        
        for(i=0; i<p.size(); i++)
            window[s[i]]++;
        
        if(window == mp) {
            ans.push_back(j);
        }

        for(i; i<s.size(); i++){
            window[s[j]]--;
            if(window[s[j]]==0) window.erase(s[j]);
            window[s[i]]++;
            j++;
            if(window==mp) ans.push_back(j);
        }

        return ans;
    }
};