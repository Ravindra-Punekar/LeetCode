class Solution {
public:
    int solve(int ind, int d, int n, vector<int>&jobDiff, vector<vector<int>>& dp){
        if(d==1){   
            int rightMax=0;
            for(int i=ind; i<n; i++){
                rightMax=max(rightMax, jobDiff[i]);
            }
            return rightMax;
        } 
    
        if(dp[d][ind]!=-1) return dp[d][ind];

        int leftMax=0;
        int ans=INT_MAX;
        for(int i=ind; i<n-d+1; i++){
            leftMax=max(leftMax,jobDiff[i]);
            ans=min(ans,leftMax+solve(i+1, d-1, n, jobDiff, dp));
        }

        dp[d][ind]=ans;
        return ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size()) return -1;
        else if(d==jobDifficulty.size())
            return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);

        int n = jobDifficulty.size();
        vector<vector<int>> dp(d+1,vector<int>(n+1,-1));


        return solve(0, d, n, jobDifficulty, dp);
    }
};
