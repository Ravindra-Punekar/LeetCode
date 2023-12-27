class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        for(int i=0; i<colors.size(); i++){
            int j=i;
            int sum=0, mx = 0;
            while(j<colors.size() && colors[j]==colors[i]){
                sum+=neededTime[j];
                mx = max(mx,neededTime[j]);
                j++;
            }
            time += sum-mx;
            i=j-1;
        }
        return time;
    }
};