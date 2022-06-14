class Solution {
public:
     bool bfs(vector<vector<int>> &graph,vector<int> &v,int i)
     {
        int n=graph.size();
        queue<int> q;
        q.push(i);
        v[i]=0;
        int colour=0;
        
        while(!q.empty())
        {
            int curr=q.front();
            int color=v[curr];
            q.pop();
            for(auto x:graph[curr])
            {
                if(v[x]!=-1)
                {
                    if(v[x]==color)
                    {
                        return false;
                    }
                }
                else
                {
                    v[x]=1-color;
                    q.push(x);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto d:dislikes)
        {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        vector<int> v(n+1,-1);
        bool ok=true;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==-1)
            {
                v[i]=0;
                ok&=bfs(adj,v,i);
            }
        }
        return ok;
    }
};