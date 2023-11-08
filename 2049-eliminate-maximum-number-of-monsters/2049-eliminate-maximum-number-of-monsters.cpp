class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float> time(n,0);
        for(int i=0;i<n;i++){
            time[i]=ceil((float)dist[i]/speed[i]);
        }
        sort(time.begin(), time.end());

        int count = 0;
        
        for (int i = 0; i < time.size(); i++) {
            if (time[i] <= i) {
                break;
            }
            count++;
        }
        
        return count;
    }
};