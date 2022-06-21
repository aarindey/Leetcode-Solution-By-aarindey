class Solution {
public:
    void dfs(vector<set<int>> &adj,vector<bool> &vis,int node)
    {
        vis[node]=true;
        for(auto &x:adj[node])
        {
            if(!vis[x])
            {
                dfs(adj,vis,x);
            }
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<set<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        for(int i=0;i<n;i++)
        {
            adj[edges[i][0]].insert(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        for(int i=n-1;i>=0;i--)
        {
            adj[edges[i][0]].erase(edges[i][1]);
            indegree[edges[i][1]]--;
            
            int startNode=-1;
            for(int j=1;j<=n;j++)
            {
                if(indegree[j]==0)
                {
                    startNode=j;
                    break;
                }
            }
            if(startNode==-1)
            {
                continue;
            }
            vector<bool> vis(n+1,false);
            dfs(adj,vis,startNode);
            bool ok=true;
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==false)
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                return {edges[i][0],edges[i][1]};
            }
            adj[edges[i][0]].insert(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        return {};
    }
};