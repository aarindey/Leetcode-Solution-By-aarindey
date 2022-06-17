class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> rowCount(m,0);
        vector<int> colCount(n,0);
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                c+=grid[i][j];
            }
            rowCount[i]=c;
            if(c>1)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j])
                    {
                        vis[i][j]=1;
                    }
                }
            }
        }
        vector<int> colCommon(n,0);
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<m;j++)
            {
                if(vis[j][i])
                c++;
            }
            colCommon[i]=c;
        }
        for(int j=0;j<n;j++)
        {
            int c=0;
            for(int i=0;i<m;i++)
            {
                c+=grid[i][j];
            }
            colCount[j]=c;
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            if(rowCount[i]>1)
            {
                ans+=rowCount[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<colCommon[i]<<endl;
        }
        for(int j=0;j<n;j++)
        {
            if(colCount[j]>1)
            {
                ans=ans+colCount[j]-colCommon[j];
            }
        }
        return ans;
    }
};