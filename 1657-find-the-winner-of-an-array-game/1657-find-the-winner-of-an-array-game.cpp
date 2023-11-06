class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k>=n) return *max_element(arr.begin(), arr.end());
        
        int i=0, j=1;
        int count=0;
        int curr=arr[i];

        while(count!=k){
            if(arr[i]>arr[j]){
                count++;
                // cout<<arr[i]<<arr[j]<<count<<"a ";
                j = (j+1)%n;
            }else{
                count=1;
                // cout<<arr[i]<<arr[j]<<count<<"b ";
                i=j;
                j = (j+1)%n;
            }
        }
        return arr[i];
    }
};