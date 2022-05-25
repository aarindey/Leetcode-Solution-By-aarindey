class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> maxCol(n);
        vector<int> maxRow(n);
        for(int i=0;i<n;i++)
        {
            int maxi=INT_MIN;
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,grid[i][j]);
            }
            maxCol[i]=maxi;
        }
        for(int j=0;j<m;j++)
        {
            int maxi=INT_MIN;
            for(int i=0;i<n;i++)
            {
                maxi=max(maxi,grid[i][j]);
            }
            maxRow[j]=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(min(maxRow[j],maxCol[i])>grid[i][j])
                ans+=min(maxRow[j],maxCol[i])-grid[i][j];
            }
        }
        return ans;
    }
};