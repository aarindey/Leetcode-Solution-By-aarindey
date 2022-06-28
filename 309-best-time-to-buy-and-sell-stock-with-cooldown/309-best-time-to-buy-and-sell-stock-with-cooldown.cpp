class Solution {
public:
    int fun(vector<int> &prices,int i,int bought,int n,vector<int> &dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[bought]!=-1)
        return dp[bought];
        
        if(prices[i]<=prices[bought])
        {
            bought=i;
            return dp[bought]=fun(prices,i+1,bought,n,dp);
        }
        else
        {
            int ans=fun(prices,i+1,bought,n,dp);
            ans=max(ans,prices[i]-prices[bought]+fun(prices,i+2,i+2,n,dp));
            return dp[bought]=ans;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1,-1);
        return fun(prices,0,0,n,dp);
    }
};