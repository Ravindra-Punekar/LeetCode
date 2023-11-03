class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> output;

        int k=1,i=0;
       for(int i=0;i<target.size(); i++){
            if(target[i]==k++)
                output.push_back("Push");
            else{
                output.push_back("Push");     
                output.push_back("Pop");
                i--;     
            }
        }

        return output;
    }
};