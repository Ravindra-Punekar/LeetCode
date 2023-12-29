class Solution {
public:
    string countAndSay(int n) {
        string say = "1";

        for(int i=1; i<n; i++){
            string temp = "";
            
            for(int j=0; j<say.size(); j++){
                int count = 1; 
                while(j+1<say.size() && say[j]==say[j+1]){
                    count++;
                    j++;
                }
                temp += to_string(count) + say[j];
            } 

            say = temp;
        }
        return say;
    }
};