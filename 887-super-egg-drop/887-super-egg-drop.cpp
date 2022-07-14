class Solution {
public:
    int solve(int k,int n,vector<vector<int>> &dp)
    {
        if(n==0)
        return 0;
        if(n==1)
        {
            return 1;
        }
        if(k==1)
        {
            return n;
        }
        if(dp[k][n]!=-1)
        return dp[k][n];
        int ans=INT_MAX;
        int curr=INT_MIN;
        int low=1,high=n;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int t1,t2;
            t1=dp[k-1][mid-1]!=-1?dp[k-1][mid-1]:dp[k-1][mid-1]=solve(k-1,mid-1,dp);
            t2=dp[k][n-mid]!=-1?dp[k][n-mid]:dp[k][n-mid]=solve(k,n-mid,dp);
            if(t1<t2)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        ans=min({max(1+dp[k-1][low-1],1+dp[k][n-low]),max(1+dp[k-1][high-1],1+dp[k][n-high])});        
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};