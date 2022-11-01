class Solution {
public:
    int n,m;
    bool isValid(int r,int c)
    {
        return (r>=0&&r<n)&&(c>=0&&c<m);
    }
    int recurse(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &memo)
    {
        if(r==n)
        return c;
        if(isValid(r,c))
        { 
        if(grid[r][c]==1&&isValid(r,c+1)&&grid[r][c+1]==1)
        {
            if(memo[r+1][c+1]!=-2)
            {
                return memo[r+1][c+1];
            }
            else
            {
                return memo[r+1][c+1]=recurse(r+1,c+1,grid,memo);
            }
        }
        if(grid[r][c]==-1&&isValid(r,c-1)&&grid[r][c-1]==-1)
        {
            if(memo[r+1][c-1]!=-2)
            {
                return memo[r+1][c-1];
            }
            else
            {
                return memo[r+1][c-1]=recurse(r+1,c-1,grid,memo);
            }
        }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> memo(n+1,vector<int>(m+1,-2));
        vector<int> ans;
        for(int j=0;j<m;j++)
        {
            ans.push_back(recurse(0,j,grid,memo));
        }
        return ans;
    }
};