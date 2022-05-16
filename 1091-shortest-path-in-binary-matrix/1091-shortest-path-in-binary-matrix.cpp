class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n,m;
        n=grid.size();
        m=grid[0].size();
        vector<pair<int,int>> dir={{1,1},{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{-1,-1}};
        if(grid[0][0]!=0)
        return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            if(x==n-1&&y==m-1)
            return grid[x][y];
            for(auto pr:dir)
            {
                int new_x,new_y;
                new_x=x+pr.first;
                new_y=y+pr.second;
                if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m&&grid[new_x][new_y]==0)
                {
                    grid[new_x][new_y]=grid[x][y]+1;
                    q.push({new_x,new_y});
                }
            }
            q.pop();
        }
        return -1;
    }
};