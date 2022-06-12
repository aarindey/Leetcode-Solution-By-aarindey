class Solution {
public:
    int solve(vector<vector<int>> &grid,vector<vector<int>> &moveCost,int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==n-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int res=INT_MAX;
        for(int k=0;k<m;k++)
        {
            res=min(res,grid[i][j]+moveCost[grid[i][j]][k]+solve(grid,moveCost,i+1,k,n,m,dp));
        }
        return dp[i][j]=res;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int j=0;j<m;j++)
        {
            ans=min(ans,solve(grid,moveCost,0,j,n,m,dp));
        }
        return ans;
    }
};