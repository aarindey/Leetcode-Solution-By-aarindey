class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]&&!vis[i][j])
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=true;
                    int area=0;
                    while(!q.empty())
                    {
                        pair<int,int> ele=q.front();
                        q.pop();
                        // cout<<ele.first<<" "<<ele.second<<endl;
                        area++;
                        //vis[ele.first][ele.second]=true;
                        for(int i=0;i<4;i++)
                        {
                            int new_x=ele.first+dx[i];
                            int new_y=ele.second+dy[i];
                            if(new_x<0||new_y<0)
                            continue;
                            if(new_x>=n||new_y>=m)
                            continue;
                            if(!vis[new_x][new_y]&&grid[new_x][new_y])
                            {
                                q.push({new_x,new_y});
                                vis[new_x][new_y]=true;
                            }
                        }
                    }
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};