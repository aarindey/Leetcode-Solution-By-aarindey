class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
      int m=grid.size(),n=grid[0].size();
      vector<vector<int> > ans(m,vector<int>(n,0));
      for(int i=0;i<n*m;i++)
      {
          int org_x=i%n;
          int org_y=i/n;
          int new_x,new_y;
          new_x=(org_x+k)%n;
          new_y=(org_y+(org_x+k)/n)%m;
          ans[new_y][new_x]=grid[org_y][org_x];
      }
        return ans;
    }
};