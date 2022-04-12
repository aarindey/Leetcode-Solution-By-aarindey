class Solution {
public:
    void dfs(vector<vector<int> > &g,vector<vector<bool>> &v,int i,int j)
    {
        int n=g.size();
        int m=g[0].size();
        if(i<0||i>=n)
        {
            return;
        }
        if(j<0||j>=m)
        {
            return;
        }
        if(v[i][j]||g[i][j])
        {
            return;
        }
        g[i][j]=1;
        v[i][j]=true;
        dfs(g,v,i+1,j);
        dfs(g,v,i-1,j);
        dfs(g,v,i,j+1);
        dfs(g,v,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
      int n=grid.size(),m=grid[0].size();
      vector<vector<bool> > vis(n,vector<bool>(m,false));
      for(int i=0;i<n;i++)
      {
          if(!vis[i][0]&&!grid[i][0])
          {
              dfs(grid,vis,i,0);
          }
          if(!vis[i][m-1]&&!grid[i][m-1])
          {
              dfs(grid,vis,i,m-1);
          }
      }
      for(int j=0;j<m;j++)
      {
          if(!vis[0][j]&&!grid[0][j])
          {
              dfs(grid,vis,0,j);
          }
          if(!vis[n-1][j]&&!grid[n-1][j])
          {
              dfs(grid,vis,n-1,j);
          }
      }
        int c=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(!vis[i][j]&&!grid[i][j])
                {
                    c++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return c;
    }
};