#define ll long long int
class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool> &vis,ll &c,int i)
    {
        vis[i]=true;
        c++;
        for(int x:adj[i])
        {
            if(!vis[x])
            dfs(adj,vis,c,x);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        ll n=bombs.size();
        vector<vector<int>> adj(n);
        for(ll i=0;i<n;i++)
        {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(ll j=0;j<n;j++)
            {
                if(i!=j)
                {
                ll x2,y2,r2;
                x2=bombs[j][0];
                y2=bombs[j][1];
                r2=bombs[j][2];
                ll d1=abs(x1-x2);
                ll d2=abs(y1-y2);
                if(d1*d1+d2*d2<=r1*r1)
                {
                    adj[i].push_back(j);
                }
                }
            }
        }
        ll c=0;
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            c=0;
            vector<bool> visited(n,false);
            dfs(adj,visited,c,i);
            ans=max(ans,c);
        }
        return ans;
    }
};