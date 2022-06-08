class Solution {
public:
    int bfs(vector<vector<int>> &v,int n)
    {
        queue<pair<int,int>> q;
        if(v[0][0]==0||v[n-1][n-1]==0)
        return false;
        q.push({0,0});
        vector<int> dx,dy;
        dx={1,-1,0,0};
        dy={0,0,1,-1};
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        while(!q.empty())
        {
            pair<int,int> ele=q.front();
            q.pop();
            int x=ele.first;
            int y=ele.second;
            for(int i=0;i<4;i++)
            {
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0&&new_x<n&&new_y>=0&&new_y<n&&v[new_x][new_y]==1&&!vis[new_x][new_y])
                {
                    if(new_x==n-1&&new_y==n-1)
                    {
                        return true;
                    }
                    vis[new_x][new_y]=true;
                    q.push({new_x,new_y});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int low=0;
        int high=n*n;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            vector<vector<int>> temp;
            temp=grid;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(temp[i][j]<=mid)
                    {
                        temp[i][j]=1;
                    }
                    else
                    {
                        temp[i][j]=0;
                    }
                }
            }
            if(bfs(temp,n))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};