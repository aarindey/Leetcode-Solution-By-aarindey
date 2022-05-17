class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;j++)
                {
                    grid[i][j]^=1;
                }
            }
        }
        vector<int> colSum(m,0);
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==1)
                colSum[j]++;
            }
        }
        for(int j=0;j<m;j++)
        {
            if(colSum[j]<n-colSum[j])
            {
                for(int i=0;i<n;i++)
                {
                    grid[i][j]^=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int t=0;
            for(int j=m-1;j>=0;j--)
            {
                t+=grid[i][j]*pow(2,m-1-j);
            }
            ans+=t;
        }
        return ans;
    }
};