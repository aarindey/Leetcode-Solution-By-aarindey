#define ll long long int
class Solution {
public:
    int coinChange(vector<int>& v, int sum) {
        int n=v.size();
       vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
for(ll i=1;i<=sum;i++)
{
    dp[0][i]=INT_MAX-1;
}
for(ll i=1;i<=sum;i++)
{
    if(i%v[0]==0)
    {
        dp[1][i]=i/v[0];
    }
    else{
        dp[1][i]=INT_MAX-1;
    }
}
for(ll i=2;i<=n;i++)
{
    for(ll j=1;j<=sum;j++)
    {
        if(j<v[i-1])
        {
             dp[i][j]=dp[i-1][j];
        }
        else{
            dp[i][j]=min(dp[i-1][j],(ll)(1+dp[i][j-v[i-1]]));
        }
    }
}
        return dp[n][sum]==INT_MAX-1?-1:dp[n][sum];
    }
};
