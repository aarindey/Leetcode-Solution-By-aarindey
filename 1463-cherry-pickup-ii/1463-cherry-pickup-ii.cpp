class Solution {
public:
    int helper(vector<vector<vector<int>>> &dp,vector<vector<int>> &grid,int c1,int c2,int r)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(r==n)
        return 0;
        if(dp[c1][c2][r]!=-1)
        return dp[c1][c2][r];
        
        int ans=0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int C1,C2;
                C1=c1+i;
                C2=c2+j;
                if(C1>=0&&C1<m&&C2>=0&&C2<m)
                ans=max(ans,helper(dp,grid,C1,C2,r+1));
            }
        }
        if(c1==c2)
        {
            ans+=grid[r][c1];
        }
        else
        {
            ans+=(grid[r][c1]+grid[r][c2]);
        }
        return dp[c1][c2][r]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(70,vector<vector<int>>(70,vector<int>(70,-1)));
        return helper(dp,grid,0,grid[0].size()-1,0);
    }
};