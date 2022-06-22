{
return false;
}
else
{
return true;
}
}
else if(new_y==m-1)
{
​
if(grid[new_x][new_y]==1)
{
return false;
}
else
{
return true;
}
}
return true;
}
int minCost(vector<vector<int>>& grid) {
n=grid.size();
m=grid[0].size();
vector<vector<pair<int,int>>> adj(m*n);
vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,1,-1};
vector<bool> vis(m*n,false);
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
int num=i*n+j%m;
for(int k=0;k<4;k++)
{