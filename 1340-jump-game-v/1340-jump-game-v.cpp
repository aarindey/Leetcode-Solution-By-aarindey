class Solution {
public:
    int n;
    int fun(vector<int> &arr,int d,int i,vector<int> &dp)
    {
        int ans=1;
        if(dp[i]!=-1)
        return dp[i];
        for(int j=i+1;j<=min(i+d,n-1)&&arr[j]<arr[i];j++)
        ans=max(ans,1+fun(arr,d,j,dp));
        for(int j=i-1;j>=max(0,i-d)&&arr[j]<arr[i];j--)
        ans=max(ans,1+fun(arr,d,j,dp));
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        int ans=0;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++)
        ans=max(ans,fun(arr,d,i,dp));
        return ans;
    }
};