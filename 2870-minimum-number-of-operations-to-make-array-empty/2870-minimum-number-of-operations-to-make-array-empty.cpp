class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;

        int op = 0;
        for (auto i : mp) {
            int n = i.second;
            if (n == 1)
                return -1;

            op += (n == 2) ? 1 : (n%3 == 0)? n/3 : n/3 + 1;
        }
        return op;
    }
};
