class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<int>> &grid1,vector<vector<int>> &grid2)
    {
        if(i<0||j<0||i>=n||j>=m)
        {
            return true;
        }
        if(grid2[i][j]==0)
        {
            return true;
        }
        else
        {
            if(grid1[i][j]==0)
            {
                return false;
            }
        }
        grid2[i][j]=0;
        bool ans=true;
        
        ans&=dfs(i+1,j,n,m,grid1,grid2);
        ans&=dfs(i,j+1,n,m,grid1,grid2);
        ans&=dfs(i-1,j,n,m,grid1,grid2);
        ans&=dfs(i,j-1,n,m,grid1,grid2);
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int i=0,j=0,n,m;
        n=grid1.size();
        m=grid1[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                      if(dfs(i,j,n,m,grid1,grid2))
                        c++;
                }
            }
        }
        return c;
    }
};