class Solution {
public:
    int minimumSum(int n, int k) {
        int mid=k/2;
        if (n <= mid) {
            return n*(n + 1)/2;
        }

        int sum = mid*(mid+1)/2;
        
        int remNum = n - mid;
        sum += remNum*(2*k + (remNum-1))/2;
        return sum;
    }
};