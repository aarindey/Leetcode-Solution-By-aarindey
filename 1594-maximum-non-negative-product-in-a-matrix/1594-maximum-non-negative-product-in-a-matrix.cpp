#define ll long long int
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        ll mod=1e9+7;
        ll n=grid.size();
        ll m=grid[0].size();
        vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(m));
        dp[0][0].first=grid[0][0];
        dp[0][0].second=grid[0][0];
        for(ll i=1;i<n;i++)
        {
            dp[i][0].first=dp[i][0].second=dp[i-1][0].first*grid[i][0];
        }
        for(ll i=1;i<m;i++)
        {
            dp[0][i].first=dp[0][i].second=dp[0][i-1].first*grid[0][i];
        }
        // if(n==1)
        // {
        //     return (dp[0][m-1].first<0)?-1:dp[0][m-1].first%mod;
        // }
        // if(m==1)
        // {
        //     return (dp[n-1][0].first<0)?-1:dp[n-1][0].first%mod;
        // }
        // first -> max     second->min
        for(ll i=1;i<n;i++)
        {
            for(ll j=1;j<m;j++)
            {
                if(grid[i][j]<0)
                {
                    dp[i][j].first=grid[i][j]*(min(dp[i-1][j].second,dp[i][j-1].second));
                    dp[i][j].second=grid[i][j]*(max(dp[i-1][j].first,dp[i][j-1].first));
                }
                else
                {
                    dp[i][j].first=grid[i][j]*(max(dp[i-1][j].first,dp[i][j-1].first));
                    dp[i][j].second=grid[i][j]*(min(dp[i-1][j].second,dp[i][j-1].second));
                }
            }
            
        }
        if(dp[n-1][m-1].first<0)
        return -1;
        
        return (dp[n-1][m-1].first)%mod;
    }
};