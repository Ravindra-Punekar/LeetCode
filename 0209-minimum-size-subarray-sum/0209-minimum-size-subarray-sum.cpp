class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = 100001;
        int j=0;
        int sum=0;
        for(int i=0; i<nums.size() && j<nums.size(); i++){
            sum += nums[i];
            if(sum>=target){
                while( sum>=target )sum -= nums[j++];
                minLen = min(minLen, i-j+1);
            }  
        }

        return minLen==100001? 0: minLen+1;
    }
};