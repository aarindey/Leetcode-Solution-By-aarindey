#define ll long long int
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<ll> dp(amount+1,INT_MAX);
        dp[0]=0;
        ll n=coins.size();
        for(ll i=0;i<n;i++)
        {
            for(ll j=1;j<=amount;j++)
            {
                if(j>=coins[i])
                {
                    dp[j]=min(1+dp[j-coins[i]],dp[j]);
                }
            }
        }
        if(dp[amount]==INT_MAX)
        return -1;
        
        return dp[amount];
    } 
};