class Solution {
public:
    int solve(int ind, int n, vector<int>& dp, vector<vector<int>>& jobs, vector<int>& st){
        if(ind>=n) return 0;  
        
        if(dp[ind]!=-1) return dp[ind];
       
        //for choose, next job start time >= end time of curr. job
        int next = lower_bound(st.begin(), st.end(), jobs[ind][1]) - st.begin();
        int choose = jobs[ind][2] + solve(next, n, dp, jobs, st);
        
        int dontChoose = solve(ind+1, n, dp, jobs, st);
        return dp[ind] = max(choose, dontChoose);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        vector<vector<int>>jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back(
                {startTime[i], endTime[i], profit[i]}
            );
        }

        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        vector<int> dp(n, -1);
        
        return solve(0, n, dp, jobs, startTime);
    }
};

/*
dp 
choose or not choose
upper_bound/lower_bound

[0,0,0,0,0]

i=0, 
if choose, 
    p += prof[0], l=st[0], r=et[0]=3
    i=1
    find 1st element from startTime equal or greater than r/  
    endTime[i] 
    then 
    choose or not choose
else
    p += 0, 






*/