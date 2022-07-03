#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int n,m;
    bool isvalid(int i,int j)
    {
        return (i>=0&&i<n&&j>=0&&j<m);
    }
    int dfs( int i, int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(dp[i][j]!=0)
        return dp[i][j];
        if(i<0||j<0||i>=n&&j>=m)
        return 0;
        int ans=1;
        for(int k=0;k<4;k++)
        {
            int new_x,new_y;
            new_x=i+dx[k];
            new_y=j+dy[k];
            
            if(isvalid(new_x,new_y)&&grid[new_x][new_y]>grid[i][j])
            {
                ans=(ans%mod+dfs(new_x,new_y,dp,grid)%mod)%mod;
            }
        }
        
        return dp[i][j]=ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dp(n,vector<int>(m,0));
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 sum=(sum%mod+dfs(i,j,dp,grid)%mod)%mod;
            }
        }
        return sum%mod;
    }
};