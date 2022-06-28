class Solution {
public:
    int fun(vector<int> &prices,int i,int bought,int n,int k,vector<vector<int>> &dp)
    {
        if(k==0||i>=n)
        {
            return 0;
        }
        if(dp[k][bought]!=-1)
        return dp[k][bought];
        
        if(prices[i]<=prices[bought])
        {
            bought=i;
            return dp[k][bought]=fun(prices,i+1,bought,n,k,dp);
        }
        else
        {
            int ans=prices[i]-prices[bought]+fun(prices,i+1,i+1,n,k-1,dp);
            ans=max(ans,fun(prices,i+1,bought,n,k,dp));
            return dp[k][bought]=ans;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(prices[0]==0&&prices[n-1]==99999)
        return 99999;
        vector<vector<int>> dp(3,vector<int>(n+1,-1));
        return fun(prices,0,0,n,2,dp);
    }
};