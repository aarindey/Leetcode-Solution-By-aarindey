  class Solution {
public:
    int n,m;
	bool isValid(vector<vector<int>>& grid,int new_x,int new_y,int x,int y)
    {
        // R L D U
        //2 2 2 
        //2 2 2
        // new_x =1 new_y=0
        
        if(grid[x][y] == 1 && new_x == x && new_y == y+1)
            return true;
        if(grid[x][y] == 2 && new_x == x && new_y == y-1)
            return true;
        if(grid[x][y] == 3 && new_x == x+1 && new_y == y)
            return true;
        if(grid[x][y] == 4 && new_x == x-1 && new_y == y)
            return true;
        
        return false;
    }
		int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<pair<int,int>>> adj(m*n);
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int num=i*m+j;
                // cout<<num<<endl;
                for(int k=0;k<4;k++)
                {
                    int new_x,new_y;
                    new_x=i+dx[k];
                    new_y=j+dy[k];
                    if(new_x>=0&&new_y>=0&&new_x<n&&new_y<m)
                    {
                        int num2=new_x*m+new_y;
                        // cout<<num2<<endl;
                        if(isValid(grid,new_x,new_y,i,j))
                        {
                            adj[num].push_back({num2,0});
                            // adj[num2].push_back({num,0});
                        }
                        else
                        {
                            adj[num].push_back({num2,1});
                            // adj[num2].push_back({num,1});
                        }
                        // vis[num2]=true;
                        // vis[num]=true;
                    }
                }
            }
        }
            // for(int i=0;i<m*n;i++)
            // {
            //     cout<<i<<endl;
            //     for(int j=0;j<adj[i].size();j++)
            //     {
            //         cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
            //     }
            //     cout<<endl;
            //     cout<<endl;
            // }
        vector<int> dis(m*n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        dis[0]=0;
        while(!pq.empty())
        {
            pair<int,int> ele=pq.top();
            pq.pop();
            int dist=ele.first;
            for(auto &x:adj[ele.second])
            {
                if(dis[x.first]>dist+x.second)
                {
                    dis[x.first]=dist+x.second;
                    pq.push({dist+x.second,x.first});
                }
            }
        }
        if(dis[m*n-1]==INT_MAX)
        return -1;
        
        return dis[m*n-1];
    }
};