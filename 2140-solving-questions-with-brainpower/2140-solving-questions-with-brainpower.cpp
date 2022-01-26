#define ll long long
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
    ll n=questions.size();
        vector<ll> dp(n,0);
        dp[n-1]=questions[n-1][0];
        ll ans=dp[n-1];
        for(ll i=n-2;i>=0;i--)
        {
         int nextSolvableRound=i+1+questions[i][1];
         if(nextSolvableRound>=n)
         {
             if(i+1<n)
             dp[i]+=max((ll)questions[i][0],dp[i+1]);
             else
             dp[i]+=questions[i][0];
             ans=max(ans,dp[i]);
         }
         else
         {
             dp[i]+=max((ll)(questions[i][0]+dp[nextSolvableRound]),dp[i+1]);
             ans=max(ans,dp[i]);
         }
        }
        return ans;
    }
};