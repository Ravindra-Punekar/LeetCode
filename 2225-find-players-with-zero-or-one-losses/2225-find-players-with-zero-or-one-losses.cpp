class Solution {
public:
    struct f {
        int w; // win count
        int l; // lost count
        int t; // total matches
    };
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        map<int, f> mp;
        for (int i = 0; i < matches.size(); i++) {
            mp[matches[i][0]].w++;
            mp[matches[i][1]].l++;
            mp[matches[i][0]].t++;
            mp[matches[i][1]].t++;
        }

        vector<vector<int>> ans(2);
        for (auto [n, c] : mp) {
            if (c.w == c.t)
                ans[0].push_back(n);

            if (c.l == 1)
                ans[1].push_back(n);
        }

        return ans;
    }
};