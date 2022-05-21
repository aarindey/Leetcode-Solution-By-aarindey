class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int j=1;j<=amount;j++)
        {
            if(j%coins[0]==0)
             dp[0][j]=j/coins[0];
            else
             dp[0][j]=INT_MAX-1;   
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i]>j)
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i]]);    
            }
        }
        return dp[n-1][amount]==INT_MAX-1?-1:dp[n-1][amount];
    }
};
