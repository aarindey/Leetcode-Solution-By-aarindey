class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3,vector<int>(n+1,0));
        for(int i=1;i<=2;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1)
                {
                    dp[i][j]=j;
                }
                else if(j==1)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int mini=INT_MAX;
                    for(int mj=j-1,pj=0;mj>=0;mj--,pj++)
                    {
                        int v1=dp[i][mj];
                        int v2=dp[i-1][pj];
                        int val=max(v1,v2);
                        mini=min(mini,val);
                    }
                    dp[i][j]=mini+1;
                }
            }
        }
        return dp[2][n];
    }
};