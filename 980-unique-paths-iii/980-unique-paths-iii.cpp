class Solution {
public:
    int ans=0;
    bool isValid(int x,int y,vector<vector<int>> &grid)
    {
        if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size())
        {
            if(grid[x][y]==-1)
            return false;
            
            return true;
        }
        return false;
    }
    void dfs(int x,int y,vector<vector<int>> &grid,int empty)
    {
        if(!isValid(x,y,grid))
        return;
        
        if(grid[x][y]==2)
        {
            if(empty==-1)
            ans++;
            return;
        }
        
        grid[x][y]=-1;
        dfs(x+1,y,grid,empty-1);
        dfs(x,y+1,grid,empty-1);
        dfs(x-1,y,grid,empty-1);
        dfs(x,y-1,grid,empty-1);
        grid[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      int empty=0;
      int x,y;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j]==0)
              empty++;
              else if(grid[i][j]==1)
              {
                  x=i;
                  y=j;
              }
          }
      }
      dfs(x,y,grid,empty);
      return ans;
    }
};