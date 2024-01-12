class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();
        int first=0, second=0;
        
        for(int i=0;i<=(n/2)-1;i++)
            if(st.find(s[i])!=st.end()) first++;

        for(int i=n/2;i<n;i++)
            if(st.find(s[i])!=st.end()) second++;
        
        return first==second;
    }
};