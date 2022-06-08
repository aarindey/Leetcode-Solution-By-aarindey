class Solution {
public:

    bool bfs(vector<vector<int>> &cells,vector<vector<int>> &v,int row,int col)
    {
        vector<int> dx,dy;
        dx={1,-1,0,0};
        dy={0,0,1,-1};
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for(int i=0;i<col;i++)
        {
            if(v[0][i]==0)
            {
                visited[0][i]=true;
                q.push({0,i});
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> ele=q.front();\
            q.pop();
            int x=ele.first;
            int y=ele.second;
            if(x==row-1)
            {
                return true;
            }
            for(int i=0;i<4;i++)
            {
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0&&new_x<row&&new_y>=0&&new_y<col&&v[new_x][new_y]==0&&!visited[new_x][new_y])
                {
                    if(new_x==row-1)
                    return true;
                    
                    visited[new_x][new_y]=true;
                    q.push({new_x,new_y});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int low=0;
        int high=n-1;
        int ans=low;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            vector<vector<int>> v(row,vector<int>(col,0));
            for(int i=0;i<=mid;i++)
            {
                v[cells[i][0]-1][cells[i][1]-1]=1;
            }
            if(bfs(cells,v,row,col))
            {
                ans=mid+1;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};