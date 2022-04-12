class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        for(int i=1;i<=n;i++)
        {
            bool res=false;
            for(int j=1;j*j<=i;j++)
            {
                res|=!(dp[i-j*j]);
            }
            dp[i]=res;
        }
        return dp[n];
    }
};