class Solution {
public:
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
      vector<vector<int>> dp(n,vector<int>(amount+1,1));
                             for(int j=1;j<=amount;j++)
                             {
                                 if(j%coins[0]!=0)
                                 dp[0][j]=0;
                                 else 
                                  dp[0][j]=1;
                             }
    for(int i=1;i<n;i++)
   {
        for(int j=1;j<=amount;j++)
        {
            if(j<coins[i])
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
        }
    }
      return dp[n-1][amount];
    }
};
