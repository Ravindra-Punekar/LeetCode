class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int totalCount = 0;

        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];

                if (diff >= INT_MIN && diff <= INT_MAX) {
                    int count = dp[j][diff];
                    totalCount += count;
                    dp[i][diff] += count + 1;   // dp[i][diff] - no of A.S ending at index i with diff
                }
            }
        }

        return totalCount;
    }
};

/*
Arithmetic progression: an = a + (n − 1)d
                        a, a + d, a + 2d, a + 3d
minimum 3 terms require.
a can be anything, count

dp
*/