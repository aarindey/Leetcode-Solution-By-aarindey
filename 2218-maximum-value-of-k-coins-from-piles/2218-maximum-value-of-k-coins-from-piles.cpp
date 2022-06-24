class Solution {
public:
    int n;
    int recurse(int i,int j,vector<vector<int>> &v,int k,vector<vector<int>> &dp)
    {
        if(i==n)
        return 0;
        if(k==0)
        return 0;
        if(j==0 && dp[i][k]!=-1)
        return dp[i][k];
        int ans=0;
        
        if(j+1<v[i].size())
        ans=max(ans,v[i][j]+recurse(i,j+1,v,k-1,dp));
        
        ans=max(ans,v[i][j]+recurse(i+1,0,v,k-1,dp));
        
        ans=max(recurse(i+1,0,v,k,dp),ans);
        if(j==0)
        {
            dp[i][k]=ans;
        }
        return ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k)
    {
        n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return recurse(0,0,piles,k,dp);
    }
};