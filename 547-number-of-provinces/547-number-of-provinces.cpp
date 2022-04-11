class Solution {
public:
    void bfs(vector<bool> &vis,int i,vector<vector<int> > &v)
    {
        int n=vis.size();
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            if(vis[ele])
            continue;
            
            vis[ele]=true;
            for(int j=0;j<n;j++)
            {
                if(v[ele][j]==1&&!vis[j])
                {
                q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size(),c=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
          if(!vis[i])
          {
              bfs(vis,i,v);
              c++;
          }
        }
        return c;
    }
};