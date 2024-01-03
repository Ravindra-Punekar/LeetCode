class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int beams = 0;
        int prev = 0;
        
        for(int i=0; i<bank.size(); i++){
            int curr = count(bank[i].begin(),bank[i].end(),'1');
            
            if(prev!=0 && curr!=0)
                beams += prev*curr;
            if(curr!=0) 
                prev = curr;
        }

        return beams;
    }
};