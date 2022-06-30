#define ll long long int
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<ll>> dp(m+1,vector<ll>(n+1));
        for(ll i=0;i<prices.size();i++)
        {
            dp[prices[i][0]][prices[i][1]]=prices[i][2];
        }
        for(ll i=0;i<=m;i++)
        {
            for(ll j=0;j<=n;j++)
            {
                ll ans=0;
                //considering Vertical divisions
                for(ll k=0;k<=i;k++)
                {
                    ans=max(ans,dp[i-k][j]+dp[k][j]);
                }
                //considering Horizontal divisions
                for(ll k=0;k<=j;k++)
                {
                    ans=max(ans,dp[i][j-k]+dp[i][k]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[m][n];
    }
};