class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int> > dp(n,vector<int>(m));
        int diff;
        diff=1-(dungeon[n-1][m-1]);
        if(diff<=0)
        diff=1;
        
        dp[n-1][m-1]=diff;
        
        for(int j=m-2;j>=0;j--)
        {
            diff=dp[n-1][j+1]-dungeon[n-1][j];
            if(diff<=0)
            diff=1;
            dp[n-1][j]=diff;
        }
        for(int i=n-2;i>=0;i--)
        {
            diff=dp[i+1][m-1]-dungeon[i][m-1];
            if(diff<=0)
            diff=1;
            dp[i][m-1]=diff;
        }
        for(int j=m-2;j>=0;j--)
        {
            for(int i=n-2;i>=0;i--)
            {
                diff=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                if(diff<=0)
                diff=1;
                dp[i][j]=diff;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};