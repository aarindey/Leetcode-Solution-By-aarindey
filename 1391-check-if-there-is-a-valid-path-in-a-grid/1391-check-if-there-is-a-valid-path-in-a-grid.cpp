class Solution {
public:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,-1,0,1};
    struct node{
      int x,y,code;
      node(int xx,int yy,int c)
      {
          x=xx;
          y=yy;
          code=c;
      }
    };
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<node> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push(node(0,0,grid[0][0]));
        vis[0][0]=true;
        while(!q.empty())
        {
            node ele=q.front();
            q.pop();
            int x=ele.x;
            int y=ele.y;
            if(x==n-1&&y==m-1)
            {
               return true;
            }
            int code=ele.code;
            for(int i=0;i<4;i++)
            {
                int new_x=x+dx[i];
                int new_y=y+dy[i];
              
                if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m&&!vis[new_x][new_y])
                {
                    int new_code=grid[new_x][new_y];
                    if(code==1)
                    {
                        if(new_y==y+1)
                        {
                            if(new_code==3||new_code==5||new_code==1)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                                
                        }
                        else if(new_y==y-1)
                        {
                            if(new_code==4||new_code==6||new_code==1)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                    
                        }

                    }
                    else if(code==2)
                    {
                        if(new_x==x+1)
                        {
                            if(new_code==2||new_code==5||new_code==6)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                        else if(new_x==x-1)
                        {
                            if(new_code==3||new_code==4||new_code==2)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                    }
                    else if(code==3)
                    {
                        if(new_x==x+1)
                        {
                            if(new_code==2||new_code==6||new_code==5)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                        else if(new_y==y-1)
                        {
                            if(new_code==1||new_code==4||new_code==6)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                    }
                    else if(code==4)
                    {
                        if(new_x==x+1)
                        {
                            if(new_code==2||new_code==6||new_code==5)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                        else if(new_y==y+1)
                        {
                            if(new_code==1||new_code==3||new_code==5)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                    }
                    else if(code==5)
                    {
                        if(new_x==x-1)
                        {
                            if(new_code==2||new_code==3||new_code==4)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                        else if(new_y==y-1)
                        {
                            if(new_code==4||new_code==6||new_code==1)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                    }
                    else if(code==6)
                    {
                        if(new_x==x-1)
                        {
                            if(new_code==2||new_code==4||new_code==3)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                        else if(new_y==y+1)
                        {
                            if(new_code==1||new_code==5||new_code==3)
                            {
                                vis[new_x][new_y]=true;
                                q.push(node(new_x,new_y,new_code));
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};