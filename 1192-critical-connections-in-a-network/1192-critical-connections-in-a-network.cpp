class Solution {
public:
    void dfs(vector<vector<int>> &adj,int node,vector<int> &par,vector<int> &low,vector<int> &disc,vector<vector<int>> &bridge)
    {
        static int time=0;
        
        if(disc[node]==-1)
        {
            disc[node]=time;
            low[node]=time;
        }
        time+=1;
        for(auto &v:adj[node])
        {
            if(disc[v]==-1)
            {
                par[v]=node;
                dfs(adj,v,par,low,disc,bridge);
                low[node]=min(low[v],low[node]);
            }
            else if(v!=par[node])
            {
                low[node]=min(low[node],disc[v]);
            }
            if(disc[node]<low[v])
            {
                bridge.push_back({v,node});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &con:connections)
        {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        vector<int> par(n,-1),low(n,-1),disc(n,-1);
        vector<vector<int>> bridge;
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
            {
                dfs(adj,i,par,low,disc,bridge);
            }
        }
        return bridge;
    }
};