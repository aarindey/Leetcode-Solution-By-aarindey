// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapsack(int W, int wt[], int val[], int n,int i,vector<vector<int>> &memo)
    {
        if(i==n||W==0)
        return 0;
        if(memo[i][W]!=-1)
        return memo[i][W];
        
        int pick;
        if(W>=wt[i])
        pick=val[i]+knapsack(W-wt[i],wt,val,n,i+1,memo);
        else
        pick=0;
        int nonpick=knapsack(W,wt,val,n,i+1,memo);
        return memo[i][W]=max(pick,nonpick);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> memo(n+1,vector<int>(W+1,-1));
       int ans=knapsack(W,wt,val,n,0,memo);
       return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends