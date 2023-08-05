//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/



class Solution
{
    public:
    
    static bool cmp(Item &a, Item &b){
        double l1 = (double)a.value/(double)a.weight;
        double l2 = (double)b.value/(double)b.weight;
        
        return l1 > l2; 
    } 
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        // map<int,float> mp;
        // vector<pair<int,double>> mp;
       
        // for(int i=0;i<n;i++){
        //     mp.push_back({i, arr[i].value/arr[i].weight}); 
        //     // i++;
        // }
        // sort(mp.begin(), mp.end(),
        //     [](const pair<int,double> &x, const pair<int,double> &y) {
        //             return x.second > y.second;
        //     });
        sort(arr, arr+n, cmp);
            
        // for(int i=0;i<n;i++){
        //     cout<<arr[i].value<<" "<<arr[i].weight<<endl;
        // }
        int i=0;
        double ans=0;
        while(i<n && W>0){
            int k = arr[i].weight;
            if(k<=W){
                ans+=arr[i].value;
                W -= k;
            }
            else if(W==0){ break;}
            else if(W<k){
                ans+= ((double)arr[i].value/(double)arr[i].weight)*W;
                W=0;
            }
            i++;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends