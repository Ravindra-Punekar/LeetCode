class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
		
        for(int i = 0; i<=n; i++)
        {
            int oneBits = 0;
            int num = i;
            while(num != 0)
            {
                oneBits += num%2;
                num = num/2;
            }
            ans.push_back(oneBits);
        }
        return ans;
    }
};