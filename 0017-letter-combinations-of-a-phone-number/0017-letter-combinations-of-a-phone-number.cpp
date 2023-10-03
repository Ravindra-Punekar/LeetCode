class Solution {
public:
    unordered_map<char,string> mp;
    void solve(string digits, int i, string temp, vector<string>& letters){
        if(i==digits.size()){
            letters.push_back(temp);
            return;
        }

        string values = mp[digits[i]];
        
        for(int j=0; j<values.size(); j++){
            solve(digits, i+1, temp+values[j], letters);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> letters;
        if(digits=="") return letters;


        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits, 0, "", letters);

        return letters;
        
    }
};