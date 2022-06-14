class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid1,vector<vector<int>> &grid2,bool &ok)
    {
        if(i<0||j<0||i>=n||j>=m)
        {
            return;
        }
        if(grid2[i][j]==0)
        {
            return;
        }
        else
        {
            if(grid1[i][j]==0)
            {
                ok=false;
                return;
            }
        }
        grid2[i][j]=0;
        dfs(i+1,j,n,m,grid1,grid2,ok);
        dfs(i,j+1,n,m,grid1,grid2,ok);
        dfs(i-1,j,n,m,grid1,grid2,ok);
        dfs(i,j-1,n,m,grid1,grid2,ok);
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
                      bool ok=true;
                      dfs(i,j,n,m,grid1,grid2,ok);
                        if(ok)
                        c++;
                }
            }
        }
        return c;
    }
};