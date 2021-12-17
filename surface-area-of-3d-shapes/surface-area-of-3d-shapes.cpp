class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
    int ans=0,n=grid.size();
        if(n==1)
        {
            if(grid[0][0]>0)
            ans+=2;
            ans+=4*grid[0][0];
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0||i==n-1&&j==0||i==0&&j==n-1||i==n-1&&j==n-1)
                {
                    ans+=2*grid[i][j];
                }
                else if(i==0||j==0||i==n-1||j==n-1)
                {
                    ans+=grid[i][j];
                }
                if(grid[i][j]>0)
                ans+=2;
                if(i!=0)
                {
                    ans+=abs(grid[i][j]-grid[i-1][j]);
                }
                if(j!=0)
                {
                    ans+=abs(grid[i][j]-grid[i][j-1]);   
                }
            }
        }
        return ans;
    }
};