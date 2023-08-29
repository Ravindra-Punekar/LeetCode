class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int y=0;
        for(auto c:customers) if(c=='Y') y++;
        
        int penalty=y; //if closed at 0th hour 
        int hour=0;

        int currY=0, currN=0;
        for(int i=0; i<n; i++){
            if(customers[i]=='Y') currY++;
            else currN++;

            int currPen = (y - currY)+currN;
            if(penalty>currPen){
                penalty = currPen;
                hour = i+1;
            }
        }

        return hour;
    }
};