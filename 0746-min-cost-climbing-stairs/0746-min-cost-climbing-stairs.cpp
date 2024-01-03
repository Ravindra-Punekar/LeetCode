class Solution {
public:
    int solve(int i, int n, vector<int>& dp, vector<int>& cost) {
        if (i >= n) return 0;
        if (dp[i] != -1)
            return dp[i];

        int t = cost[i] + min(
                            solve(i + 1, n, dp, cost), 
                            solve(i + 2, n, dp, cost));

        return dp[i] = t;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        
        int ans = min(
            solve(0, n, dp, cost), 
            solve(1, n, dp, cost));
        
        return ans;
    }
};

/*
[a,b,c,d,e,f,g,h,i,j,k]

start with
a ->    b          or                a->c
    c   /    d                   d   /     e
  d   e    e    f             e    f      f  g

  here 'd' is used multiple times, use dp to store cost
*/