struct node{
    int x;
    int y;
    int c;
    node(int x,int y,int c)
    {
        this->x=x;
        this->y=y;
        this->c=c;
    }
};
class Solution {
public:
    bool check(int i,int j,int n,int m,vector<int> &e)
    {
        if(i==e[0]&&j==e[1])
        {
            return false;
        }
        if(i==0||j==0||i==n-1||j==m-1)
        return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        node n1(entrance[0],entrance[1],0);
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> dir;
        dir.push_back({0,1});
        dir.push_back({0,-1});
        dir.push_back({-1,0});
        dir.push_back({1,0});
        queue<node> q;
        q.push(n1);
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        while(!q.empty())
        {
            node ele=q.front();
            q.pop();
            int i=ele.x;
            int j=ele.y;
            int c=ele.c;
            if(check(i,j,n,m,entrance))
            {
                return c;
            }
            for(int a=0;a<=3;a++)
            {
                        int new_x=i+dir[a][0];
                        int new_y=j+dir[a][1];
                        if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m&&maze[new_x][new_y]=='.'&&vis[new_x][new_y]==false)
                        {
                            vis[new_x][new_y]=true;
                            q.push(node(new_x,new_y,c+1));
                        }       
            }
            }
        return -1;
    }
};