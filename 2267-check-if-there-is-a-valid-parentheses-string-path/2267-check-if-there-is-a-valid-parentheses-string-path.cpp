class Solution {
public:
    bool solve(vector<vector<char>> &grid,int i,int j,int n,int m,vector<vector<vector<int>>> &dp,int count)
    {
        if(i>=n||j>=m)
        {
            return false;
        }
        if(count>(n+m)/2)
        {
            return dp[i][j][count]=false;
        }
        if(grid[i][j]=='(')
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count<0)
        {
            return false;
        }
        if(dp[i][j][count]!=-1)
        {
            return dp[i][j][count];
        }
        if(i==n-1&&j==m-1&&count==0)
        {
            return dp[i][j][count]=true;
        }
        bool ans=false;
        if(solve(grid,i+1,j,n,m,dp,count)||solve(grid,i,j+1,n,m,dp,count))
        {
            ans=true;
        }
        return dp[i][j][count]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(202,-1)));
        return solve(grid,0,0,n,m,dp,0);
    }
};