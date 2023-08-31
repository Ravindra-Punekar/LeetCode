#define ll long long
class Solution {
public:

    long long minimumReplacement(vector<int>& nums) {
        ll operations=0;
        int n=nums.size();
        int upperBound = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
           int curr=nums[i];
            if(curr>upperBound){
                int partitions = ceil(curr/double(upperBound));
                upperBound = curr/partitions;
                operations += partitions-1;
            }else{
                upperBound = curr;
            }
        }

        return operations;
    }
};

// Revise