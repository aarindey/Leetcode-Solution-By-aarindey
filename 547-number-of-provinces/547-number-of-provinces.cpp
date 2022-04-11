class Solution {
public:
    void dfs(vector<bool> &vis,int i,vector<vector<int> > &v)
    {
        int n=vis.size();
        if(vis[i])
        return;
        vis[i]=true;
        for(int j=0;j<n;j++)
        {
            if(v[i][j])
            {
            dfs(vis,j,v);
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
              dfs(vis,i,v);
              c++;
          }
        }
        return c;
    }
};