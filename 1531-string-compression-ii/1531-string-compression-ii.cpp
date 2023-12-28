class Solution {
public:
    int solve(int i, string& s, int k, vector<vector<int>>& dp) {

        if (k < 0)
            return s.size();

        if (s.size() - i <= k)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = solve(i + 1, s, k - 1, dp);
        int sameChars = 0, diffChars = 0, encodedLength = 0;
        for (int j = i; j < s.size() && diffChars <= k; j++) {
            if (s[i] == s[j]) {
                sameChars++;
                if (sameChars <= 2 || sameChars == 10 || sameChars == 100) {
                    encodedLength++;
                }
            } else {
                diffChars++;
            }

            ans = min(ans, solve(j + 1, s, k - diffChars, dp) + encodedLength);
        }
        return dp[i][k] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(k + 1, -1));
        return solve(0, s, k, dp);
    }
};