class Solution {
public:

    int dfs(vector<vector<int>> &grid,int r,int c)
    {
        if(c<0||r<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0)
        return 0;
        int sum=grid[r][c];
        grid[r][c]=0;
        int right=dfs(grid,r,c+1);
        int left=dfs(grid,r,c-1);
        int down=dfs(grid,r+1,c);
        int up=dfs(grid,r-1,c);
        grid[r][c]=sum;
        int ans=sum+max(right,max(left,max(up,down)));
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                int ans1=dfs(grid,i,j);
                if(ans1>ans)
                ans=ans1;
                }
            }
        }
        return ans;
    }
};