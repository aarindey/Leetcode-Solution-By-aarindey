class Solution {
public:
    void dfs(vector<vector<int>> &adj,int i,vector<bool> &vis)
    {
        vis[i]=true;
        for(int x:adj[i])
        {
            if(!vis[x])
            {
                dfs(adj,x,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {   
                    if(m[i][j])
                    adj[i].push_back(j);
                    if(m[j][i])
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis);
                c++;
            }
        }
        return c;
    }
};