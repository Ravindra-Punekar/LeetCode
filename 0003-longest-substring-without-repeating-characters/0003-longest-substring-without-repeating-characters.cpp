class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int ans=1;
        unordered_set<char> win;
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(win.count(s[i])){
                ans = max(ans, (int)win.size());
                while(win.size() && s[j]!=s[i]){
                    win.erase(s[j]);
                    j++;
                }
                // cout<<j<<" "<<i<<" ";
                j++;
            } 
            else{ 
                win.insert(s[i]);
            }
        }
        
        ans = max(ans, (int)win.size());
       
        return ans;
    }
};