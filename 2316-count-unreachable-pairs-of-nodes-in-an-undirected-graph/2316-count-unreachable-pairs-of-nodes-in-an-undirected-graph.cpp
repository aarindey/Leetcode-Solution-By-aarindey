class Solution {
public:
    #define ll long long int

    void dfs(vector<vector<ll>> &adj,vector<bool> &vis,ll i,ll &c)
    {
        vis[i]=true;
        c++;
        for(auto &x:adj[i])
        {
            if(!vis[x])
            {
                dfs(adj,vis,x,c);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<ll>> adj(n);
        for(ll i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        vector<ll> v;
    
        for(ll i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ll c=0;
                dfs(adj,vis,i,c);
                v.push_back(c);
            }
        }
        if(v.size()==1)
        return 0;
        ll ans=0;
        ll x=v.size();
        vector<ll> suf(x,0);
        suf[x-1]=v[x-1];
        for(ll i=x-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+v[i];
        }
        for(ll i=0;i<x-1;i++)
        {
            ans+=v[i]*suf[i+1];
        }
        return ans;
    }
};