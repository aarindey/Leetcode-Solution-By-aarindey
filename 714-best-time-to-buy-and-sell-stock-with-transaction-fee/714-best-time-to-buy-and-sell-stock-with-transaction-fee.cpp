class Solution {
public:
    int fun(vector<int> &prices,int i,int bought,int &n,int &fee,vector<int> &dp)
    {
        if(i>=n)
        return 0;
        
        if(dp[bought]!=-1)
        return dp[bought];
        
        if(prices[i]<=prices[bought])
        {
            bought=i;
            return dp[bought]=fun(prices,i+1,bought,n,fee,dp);
        }
        else
        {
            int ans=fun(prices,i+1,bought,n,fee,dp);
            if(prices[i]-prices[bought]>fee)
            {
                ans=max(ans,prices[i]-prices[bought]-fee+fun(prices,i+1,i+1,n,fee,dp));
            }
            return dp[bought]=ans;
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> dp(n+1,-1);
        return fun(prices,0,0,n,fee,dp);
    }
};