class Solution {
public:
    string sortVowels(string s) {
        /*collect vowel, sort, put back again */
        
        string v = "aeiouAEIOU";
        vector<char> vowels;
        for(auto ch:s)
            if(v.find(ch)<v.size()) vowels.push_back(ch);

        sort(vowels.begin(), vowels.end());

        int j=0;
        for(int i=0;i<s.size();i++){
           if(v.find(s[i])<v.size()){
                s[i] = vowels[j++];
            } 
        }

        return s;
    }
};