//dijkstra's Algorithm
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        vector<pair<int,int>> dir(4);
        dir[0]={0,1};
        dir[1]={0,-1};
        dir[2]={1,0};
        dir[3]={-1,0};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > dis(n,vector<int> (m,INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> ele=pq.top();
            pq.pop();
            int x,y,cost;
            cost=ele.first;
            x=ele.second.first;
            y=ele.second.second;
            if(x==n-1&&y==m-1)
            return cost;
            for(auto pr:dir)
            {
                int next_x,next_y;
                next_x=x+pr.first;
                next_y=y+pr.second;
                if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m&&cost+grid[next_x][next_y]<dis[next_x][next_y])
                {
                    dis[next_x][next_y]=cost+grid[next_x][next_y];
                    pq.push({dis[next_x][next_y],{next_x,next_y}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};