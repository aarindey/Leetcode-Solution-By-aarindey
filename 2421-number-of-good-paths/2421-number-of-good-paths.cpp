#define ll long long int
class Solution {
public:
    ll findParent(ll node,vector<ll>& par)
    {
        if(par[node]==node)return node;
        return par[node]=findParent(par[node],par);
    }
    void Union(ll u,ll v,vector<ll> &size,vector<ll> &par)
    {
        ll pu=findParent(u,par);
        ll pv=findParent(v,par);
        if(pu==pv)return;
        if(size[pu]<=size[pv])
        {
            par[pu]=pv;
            size[pv]++;
        }
        else
        {
            par[pv]=pu;
            size[pu]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<ll> parent(n);
        vector<ll> rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[vals[i]].push_back(i);
        }
        int ans=n;
        vector<bool> isactive(n,false);
        for(auto &pr:mp)
        {
            vector<int> v=pr.second;
            int val=pr.first;

            for(auto &z:v)
            {
                isactive[z]=true;
                for(auto &node:adj[z])
                {
                    if(isactive[node])
                    {
                        Union(node,z,rank,parent);
                    }
                }
            }
            map<int,int> mpp;
            for(auto &z:v)
            {
                mpp[findParent(z,parent)]++;
            }
            for(auto &z:mpp)
            {
                int f=z.second;
                ans+=(f)*(f-1)/2;
            }
        }
        return ans;
    }
};