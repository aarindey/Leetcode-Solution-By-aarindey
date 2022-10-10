class Solution {
public:
    long long int mod=1e9+7;
    int helper(vector<vector<int>> &grid,int i,int j,int mod_sum,int n,int m,int k,vector<vector<vector<int>>> &dp)
    {
        if(i==n-1&&j==m-1)
        {
            if((mod_sum+grid[i][j])%k==0)
            return 1;
            
            return 0;
        }
        if(i==n||j==m)
        {
            return 0;
        }
        if(dp[i][j][mod_sum]!=-1)
        return dp[i][j][mod_sum];
        
        int right=helper(grid,i,j+1,(mod_sum+grid[i][j])%k,n,m,k,dp);
        int down=helper(grid,i+1,j,(mod_sum+grid[i][j])%k,n,m,k,dp);
        return dp[i][j][mod_sum]=(right+down)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return helper(grid,0,0,0,n,m,k,dp);
    }
};