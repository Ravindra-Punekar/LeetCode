class Solution {
public:
    int minDeletions(string s) {
     
     int count = 0;

     unordered_map<int,int> mp;
     for(auto c:s) mp[c-'a']++;
     
     unordered_set<int> st;
     for(int i=0;i<26; i++){
         int freq=mp[i];
         while(freq && st.count(freq)){
             freq--;
             count++;
         }
         st.insert(freq);
     }

     return count;
    }
};